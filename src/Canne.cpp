#include "Canne.h"

Canne::Canne(Vector2f start){
    this->start=start;
    setPosition(start);
    setPosition(Vector2f(200,200));
    setOrigin(Vector2f(0,0));
    setSize(Vector2f(20.f,1.f));
    setColor(Vector3i(255,255,255));
    range=100.f;
    trotation=0.5f;
    rotat=true;
    max=true;
    hammecon.setTexture(Texture("sprites/hammecon.png"));
    hammecon.setPosition(getCollisionBox().getRight(),getCollisionBox().getBottom());
    hammecon.setOrigin(Vector2f(0,0));
    catched=nullptr;
}
void Canne::input(float power){
    range=100*power;
    
}
void Canne::update(Banc poisson){
    cerr<<getRotation()<<endl;
    if (getRotation() <trotation && rotat)
    {
        setRotation(getRotation()-0.1f);
        hammecon.setRotation(hammecon.getRotation()-0.01f);
        if (getRotation()>trotation)
        {
            rotat=false;
        }
        
    }

   if (getSize().x<range && max)
   {
        setSize(Vector2f(getSize().x+1,getSize().y));
        setRotation(getRotation()-0.001f);
        if (range-getSize().x<3)
        {
            max=false;
        }
        
   }
   
   if (getRotation()>-1 && getRotation()<2)
   {
        setRotation(getRotation()+0.001);
   }
   
   hammecon.setPosition(getPosition().x+cos(getRotation())*getSize().x,getPosition().y+sin(getRotation())*getSize().x);

   for (int i = 0; i < poisson.getFishs().size(); i++)
   {
    if (hammecon.getCollisionBox().check(poisson.getFishs()[i].getCollisionBox())&& traped!=true)
    {
        
        traped=true;
        catched=new Fish(poisson.getFish(i));
    }
   }
   prise();
   
}

int Canne::getniveau(){
    return niveau;
}

Vector2f Canne::hammeconpos(){
    return hammecon.getPosition();
}

void Canne::remonte(){
    if (getSize().x>10)
    {
        setSize(getSize().x-1,getSize().y);
    }
    max=false;
}

void Canne::draw(Scene &scene){
    scene.Draw(hammecon);
    if (catched!=nullptr)
    {
        scene.Draw(*catched);
    }
    
}

void Canne::prise(){
    if(catched != nullptr){
        catched->setPosition(hammecon.getPosition());
        catched->setRotation(hammecon.getRotation());
    }
}