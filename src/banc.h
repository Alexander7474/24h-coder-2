#pragma once 

#include <BBOP/Graphics.h>

#include "fish.h"

class Banc : public BbopDrawable 
{
private:
  std::vector<Fish> fishs; 
  std::vector<Light> fishsLight; 
  int size;
  Vector2f zoneX;
  Vector2f zoneY;

  Vector2f direction;
  Vector2f center;

public:
  Banc(int _size, float _speed, float _rotation, Vector3i _rgb);
  Banc();

  std::vector<Fish>& getFishs();
  std::vector<Light>& getFishsLight();
  Fish getFish(int i);
  void Draw(GLint* renderUniforms) const override;
  void update();
};
