#include <iostream>

#include <random>
#include "banc.h"

using namespace std;

void Banc::Draw(GLint* renderUniforms) const
{
  for(long unsigned int i = 0; i < fishs.size(); i++){
    fishs[i].Draw(renderUniforms);
  }

  //RectangleShape rect;
  //rect.setSize(10.f,10.f);
  //rect.setColor(Vector3i(255,255,255));
  //rect.setPosition(center);

  //rect.Draw(renderUniforms);
}

Banc::Banc(int _size, float _speed, float _rotation, Vector3i _rgb)
  : size(_size)
{
  for(int i = 0; i < size; i++){
    Fish fish(_speed, _rotation);
    fishs.push_back(fish);
    Light light;
    light.setIntensity(0.04f);
    light.setLinear(0.05f);
    light.setConstant(0.5f);
    light.setQuadratic(3.f);
    light.setColor(_rgb);
    fishsLight.push_back(light);
  }  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dist(2.0,6.0);
  
  direction.x = dist(gen);
  direction.y = dist(gen);

  std::uniform_real_distribution<float> pos(500,1500);
  center.x = pos(gen);
  center.y = pos(gen);

  zoneX = Vector2f(0,2000);
  zoneY = Vector2f(300,2000);
}

Banc::Banc()
  : Banc(1, 3.f, 0.01f, Vector3i(135,200,235))
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

  for(long unsigned int i = 0; i < fishs.size(); i++){
    fishs[i].update(center,fishs);
    fishsLight[i].setPosition(fishs[i].getPosition());
  }
}

std::vector<Fish>& Banc::getFishs()
{
  return fishs;
}

Fish Banc::getFish(int i)
{
  Fish result = fishs[i];
  fishs.erase(fishs.begin()+i);
  return result;
}

std::vector<Light>& Banc::getFishsLight()
{
  return fishsLight;
}
