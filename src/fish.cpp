#include <iostream>
#include <time.h>

#include "fish.h"

using namespace std;

Fish::Fish()
  : Sprite("img/fishs/fish.png")
{
  setSize(32.f,16.f);
  setOrigin(16.f,8.f);
 
  int randx = rand() % 1920;
  int randy = rand() % 1080;

  cerr << randx << " " <<  randy << endl;

  setPosition(randx,randy);
}

void Fish::update(std::vector<Fish>& copains)
{
  for(int i = 0; copains.size(); i++){
    float distance = bbopGetDistance(getPosition(), copains[i].getPosition());
    cerr << distance << endl;
  }
}
