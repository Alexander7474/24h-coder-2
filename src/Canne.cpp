#include "Canne.h"

Canne::Canne(Vector2f start){
    this->start=start;
    finish=start;
    angle=-45.0f;
    etat=idol;
}
void Canne::input(float power){
    if (throwing && power!=0)
    {
        velocity.x=cos(angle) * power;
        velocity.y=sin(angle) * power;
    }
}
void Canne::Draw(Scene scene){
    scene.Draw(line);
}

void Canne::update(Scene scene,float power){
    input(power);
    velocity.y+=0.2f;
    if (finish.y>500.0f)
    {
        throwing=false;
    }
    finish.x+=velocity.x;
    finish.y+=velocity.y;
    velocity.x=0;
    velocity.y=0;
    Draw(scene);
}