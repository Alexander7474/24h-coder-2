#pragma once
#include<BBOP/Graphics.h>

#include"banc.h"
#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>
#include <vector>

using namespace std;

class Canne : public RectangleShape
{
private:
    Vector2f start;
    float range , trotation;
    float angle;
    bool rotat,max;
    Sprite hammecon;
    bool traped;
    Fish *catched;
public:
    Canne(Vector2f start);
    void input(float power);
    void update(std::vector<Banc> poisson);
    float linesize();
    int guetscore();
    Vector2f hammeconpos();
    void remonte();
    void draw(Scene &scene);
    void prise();

    void reset();

};
