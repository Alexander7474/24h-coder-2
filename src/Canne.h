#pragma once
#include<BBOP/Graphics.h>

#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>

using namespace std;

enum State{
    idol =0,
    fall =1,
    grab =2,
    shoot=3
};

class Canne
{
private:
    State etat;
    Vector2f start;
    Vector2f finish;
    Vector2f velocity;
    float angle;
    Sprite line;
    bool throwing;
public:
    Canne(Vector2f start);
    void update(Scene carte , float power);
    void input(float power);
    void Draw(Scene carte);
};

