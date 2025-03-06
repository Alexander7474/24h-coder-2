#pragma once

#include <BBOP/Graphics.h>

class Fish : public Sprite 
{
private:
  float maxSpeed;
  Vector2f direction;
  float distanceDetect;

  int dir;

public:
  Fish();


  void goTo(Vector2f p);
  void update(std::vector<Fish>& copains);
};
