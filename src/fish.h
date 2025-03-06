#pragma once

#include <BBOP/Graphics.h>

class Fish : public Sprite 
{
private:
   
public:
  Fish();

  void update(std::vector<Fish>& copains);
};
