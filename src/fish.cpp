#include <iostream>
#include <time.h>

#include "fish.h"

using namespace std;

Fish::Fish()
  : Sprite("img/fishs/fish.png")
{
  setSize(32.f,16.f);
  setOrigin(16.f,8.f);

  speed = 0.5f;
 
  int randx = rand() % 1920;
  int randy = rand() % 1080;

  setPosition(randx,randy);
}

void Fish::update(std::vector<Fish>& copains)
{
  for(int i = 0; i < copains.size(); i++){
    float distance = bbopGetDistance(getPosition(), copains[i].getPosition());
    
    if(distance > 100.f){
      float distanceX = getPosition().x - copains[i].getPosition().x;
      float distanceY = getPosition().y - copains[i].getPosition().y;

      move(-distanceX/1000, -distanceY/1000);
    }else{
      float distanceX = getPosition().x - copains[i].getPosition().x;
      float distanceY = getPosition().y - copains[i].getPosition().y;
        
      move(distanceX/1000, distanceY/1000);
    }
  
  }
}
