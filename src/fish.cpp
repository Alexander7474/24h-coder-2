#include <iostream>
#include <time.h>

#include "fish.h"

using namespace std;

Fish::Fish()
  : Sprite("img/fishs/fish.png")
{
  setSize(64.f,32.f);
  setOrigin(32.f,16.f);

  dir = 0;
  maxSpeed = 3.0f;

  int randx = rand() % 1920;
  int randy = rand() % 1080;

  setPosition(randx,randy);

  distanceDetect = 1000.f;
}

void Fish::update(Vector2f objectif, std::vector<Fish> copains)
{
  goTo(objectif);

  for(int i = 0; i < copains.size(); i++){
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

  if(rotation - getRotation() >= 0){
    addRotation = getRotation()+0.0001f*distanceC;
  }else{
    addRotation = getRotation()-0.0001f*distanceC;
  }

  setRotation(addRotation);

  if(getPosition().x < 0){
    setPosition(1920, getPosition().y);
  }else if (getPosition().x > 1920){
    setPosition(0, getPosition().y);
  }

  if(getPosition().y < 0){
    setPosition(getPosition().x, 1080);
  }else if (getPosition().y > 1080){
    setPosition(getPosition().x, 0);
  }
  Vector2f dep(cos(addRotation),sin(addRotation));
  direction.x = maxSpeed*dep.x;
  direction.y = maxSpeed*dep.y;

  move(direction);
}
