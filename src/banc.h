#pragma once 

#include <BBOP/Graphics.h>

#include "fish.h"

class Banc : public BbopDrawable 
{
private:
  std::vector<Fish> fishs; 
  int size;
public:
  Banc(int _size);
  Banc();

  void Draw(GLint* renderUniforms) const override;
  void update();
};
