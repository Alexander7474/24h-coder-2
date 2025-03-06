#include "Canne.h"

Canne::Canne(Vector2f start){
    this->start=start;
    setPosition(start);
    setOrigin(Vector2f(0,0));
    setSize(Vector2f(20.f,1.f));
    setColor(Vector3i(255,255,255));
    range=100.f;
    trotation=1;
    rotat=true;
    max=true;
    hammecon.setTexture(Texture("sprites/hammecon.png"));
    hammecon.setPosition(getCollisionBox().getRight(),getCollisionBox().getBottom());
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

   if (getSize().x<range && max)
   {
        setSize(Vector2f(getSize().x+1,getSize().y));
        if (range-getSize().x<3)
        {
            max=false;
        }
        
   }
   
   if (getRotation()>-1 && getRotation()<1)
   {
        setRotation(getRotation()+0.001);
   }
   cerr<<max<<endl;
   hammecon.setPosition(getPosition().x+cos(getRotation())*getSize().x,getPosition().y+sin(getRotation())*getSize().x);
}

int Canne::getniveau(){
    return niveau;
}

Vector2f Canne::hammeconpos(){
    return hammecon.getPosition();
}

void Canne::remonte(){
    setSize(getSize().x-0.01,getSize().y);
}

void Canne::draw(Scene &scene){
    scene.Draw(hammecon);
}