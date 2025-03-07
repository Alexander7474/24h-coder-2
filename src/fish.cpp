#include <iostream>
#include <time.h>
#include "fish.h"

using namespace std;

Fish::Fish(float _speed, float _rotation, int t)
  : Sprite("img/fishs/fish.png")
{
  if(t == 2){
    setTexture(Texture("img/fishs/fish2.png"));
  }else if(t == 3){
    setTexture(Texture("img/fishs/fish3.png"));
  }
  setSize(32.f,16.f);
  setOrigin(16.f,8.f);

  maxSpeed = _speed;
  rotationSpeed = _rotation;

  int randx = rand() % 2000;
  int randy = rand() % 1700+300;

  setPosition(randx,randy);

  distanceDetect = 1000.f;
}

void Fish::update(Vector2f objectif, std::vector<Fish> copains)
{
  goTo(objectif);

  for(long unsigned int i = 0; i < copains.size(); i++){
    if(bbopGetDistance(getPosition(), copains[i].getPosition()) < 32.f){
      move((getPosition().x-copains[i].getPosition().x)/32.f,(getPosition().y-copains[i].getPosition().y)/32.f);
    }
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

  if(rotation > 2*M_PI)
    rotation = rotation-2*M_PI;
  if(getRotation() > 2*M_PI)
    setRotation(getRotation()-2*M_PI);

  if(rotation - getRotation() >= 0){
    addRotation = getRotation()+rotationSpeed*(distanceC/100);
  }else{
    addRotation = getRotation()-rotationSpeed*(distanceC/100);
  }

  setRotation(addRotation);

  if(getPosition().x < -100){
    setRotation(M_PI*2.f);
  }else if (getPosition().x > 2000){
    setRotation(M_PI);
  }

  if(getPosition().y < 200){
    setRotation(M_PI/2.f);
  }else if (getPosition().y > 2000){
    setRotation(M_PI/2.f+M_PI);
  }
  Vector2f dep(cos(addRotation),sin(addRotation));
  direction.x = dep.x*(distanceC/100);
  direction.y = dep.y*(distanceC/100);

  if(direction.x > maxSpeed*dep.x)
    direction.x = maxSpeed*dep.x;

  if(direction.y > maxSpeed*dep.y)
    direction.y = maxSpeed*dep.y;

  move(direction);
}
