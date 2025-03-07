#pragma once 

#include <BBOP/Graphics.h>

#include "fish.h"

class Banc : public BbopDrawable 
{
private:
  std::vector<Fish> fishs; 
  int size;
  Vector2f zoneX;
  Vector2f zoneY;

  Vector2f direction;
  Vector2f center;

public:
  Banc(int _size);
  Banc();

  std::vector<Fish>& getFishs();
  Fish getFish(int i);
  void Draw(GLint* renderUniforms) const override;
  void update();
};
