#include "banc.h"

void Banc::Draw(GLint* renderUniforms) const
{
  for(int i = 0; i < fishs.size(); i++){
    fishs[i].Draw(renderUniforms);
  }
}

Banc::Banc(int _size)
  : size(_size)
{
  for(int i = 0; i < size; i++){
    Fish fish;
    fishs.push_back(fish);
  }
}

Banc::Banc()
  : Banc(1)
{
}

void Banc::update() 
{
  for(int i = 0; i < fishs.size(); i++){
    fishs[i].update(fishs);
  }
}
