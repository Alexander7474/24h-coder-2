#pragma once

#include <BBOP/Graphics.h>

class Fish : public Sprite 
{
private:
  float maxSpeed;
  float rotationSpeed;
  Vector2f direction;
  float distanceDetect;
  int score;

public:
  Fish(float _speed, float _rotation, int t);

  void goTo(Vector2f p);
  void update(Vector2f objectif, std::vector<Fish> copains);
};
