#include <iostream>
#include <time.h>
#include <random>

#include "fish.h"

using namespace std;

Fish::Fish()
  : Sprite("img/fishs/fish.png")
{
  setSize(50.f,10.f);
  setOrigin(25.f,5.f);

  dir = 0;
  std::random_device rd;
  std::mt19937 gen(rd());

  maxSpeed = 3.0f;
  std::uniform_real_distribution<float> dist(-maxSpeed,maxSpeed);
  
  direction.x = dist(gen);
  direction.y = dist(gen);

  cerr << direction.x << endl;
 
  int randx = rand() % 1920;
  int randy = rand() % 1080;

  setPosition(randx,randy);

  distanceDetect = 1000.f;
}

void Fish::update(std::vector<Fish>& copains)
{
  Vector2f objectif(0.f,0.f);
  int copainsProche = 0;

  for(int i = 0; i < copains.size(); i++){
    float distance = bbopGetDistance(getPosition(), copains[i].getPosition());
    
    if(distance <= distanceDetect){ 
      //on essaye de réorienté la direction vers le poisson 
      objectif.x += copains[i].getPosition().x;
      objectif.y += copains[i].getPosition().y;

      copainsProche += 1;
    }
  }
    
  if(objectif.x > 0 && objectif.y > 0){
      objectif.x /= (float) copainsProche;
      objectif.y /= (float) copainsProche;
      goTo(objectif);
  }

}

void Fish::goTo(Vector2f p)
{
  float distanceC = bbopGetDistance(getPosition(), p);
  float distanceA = getPosition().x - p.x;
  float distanceB = getPosition().y - p.y;

  float rotation = acos((distanceA * distanceA + distanceC * distanceC - distanceB * distanceB) / (2 * distanceA * distanceC));

  if(distanceB < 0)
    rotation = -rotation;

  rotation+=M_PI;

  float addRotation = 0.f;


  if(rotation - getRotation() >= 0){
    addRotation = getRotation()+0.01f;
  }else{
    addRotation = getRotation()-0.01f;
  }


  setRotation(addRotation);


  if(getPosition().x < 0){
    setRotation(0.f);
  }else if (getPosition().x > 1920){
    setRotation(M_PI);
  }

  if(getPosition().y < 0){
    setRotation(M_PI/2.f);
  }else if (getPosition().y > 1080){
    setRotation(M_PI+(M_PI/2.f));
  }
  Vector2f dep(cos(addRotation),sin(addRotation));
  direction.x = maxSpeed*dep.x;
  direction.y = maxSpeed*dep.y;

  move(direction);
}
