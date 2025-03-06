#include <iostream>

#include <random>
#include "banc.h"

using namespace std;

void Banc::Draw(GLint* renderUniforms) const
{
  for(int i = 0; i < fishs.size(); i++){
    fishs[i].Draw(renderUniforms);
  }

  RectangleShape rect;
  rect.setSize(10.f,10.f);
  rect.setPosition(center);

  rect.Draw(renderUniforms);
}

Banc::Banc(int _size)
  : size(_size)
{
  for(int i = 0; i < size; i++){
    Fish fish;
    fishs.push_back(fish);
  }  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dist(-5.0,5.0);
  
  direction.x = dist(gen);
  direction.y = dist(gen);

  std::uniform_real_distribution<float> pos(0,1080);
  center.x = pos(gen);
  center.y = pos(gen);

  zoneX = Vector2f(0,1920);
  zoneY = Vector2f(0,1080);
}

Banc::Banc()
  : Banc(1)
{
}

void Banc::update() 
{
  if(center.x < zoneX.x || center.x > zoneX.y){
    direction.x = -direction.x;
  }
  if(center.y < zoneY.x || center.y > zoneY.y){
    direction.y = -direction.y;
  }
  center.x += direction.x;
  center.y += direction.y;

  for(int i = 0; i < fishs.size(); i++){
    fishs[i].update(center,fishs);
  }
}

std::vector<Fish>& Banc::getFishs()
{
  return fishs;
}
