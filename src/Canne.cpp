#include "Canne.h"

Canne::Canne(Vector2f start){
    this->start=start;
    setPosition(start);
    setOrigin(Vector2f(0,0));
    setSize(Vector2f(20.f,20.f));
    setColor(Vector3i(255,255,255));
    range=100.f;
    trotation=1;
    rotat=true;
}
void Canne::input(float power){
    range=100*power;
    trotation=-(1/power);
}
void Canne::update(){
    if (getRotation() >trotation && etat!=fall && rotat)
    {
        setRotation(getRotation()-0.01f);
        if (getRotation()<trotation)
        {
            rotat=false;
        }
        
    }

   if (getSize().x<range)
   {
        setSize(Vector2f(getSize().x+1,getSize().y));
   }
   
   if (getRotation()>-1 && getRotation()<1)
   {
        setRotation(getRotation()+0.001);
   }
   
}

int Canne::getniveau(){
    return niveau;
}