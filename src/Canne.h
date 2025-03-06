#pragma once
#include<BBOP/Graphics.h>

#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>

using namespace std;

enum State{
    idol =0,
    fall =1,
    pull =2,
    shoot=3
};

class Canne : public RectangleShape
{
private:
    State etat;
    Vector2f start;
    float range , trotation;
    float angle;
    bool rotat,max;
    Sprite hammecon;
    int niveau;
public:
    Canne(Vector2f start);
    void input(float power);
    void update();
    int getniveau();
    Vector2f hammeconpos();
    void remonte();
};

