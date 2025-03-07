#include "Canne.h"

Canne::Canne(Vector2f start){
    this->start=start;
    setPosition(start);
    setPosition(Vector2f(0,0));
    setOrigin(Vector2f(0,0));
    setSize(Vector2f(20.f,1.f));
    setColor(Vector3i(255,255,255));
    range=1000.f;
    trotation=1;
    rotat=true;
    max=true;
    hammecon.setTexture(Texture("img/hammecon.png"));
    hammecon.setPosition(getCollisionBox().getRight(),getCollisionBox().getBottom());
    hammecon.setOrigin(Vector2f(0,0));
    catched=nullptr;
    hammecon.setSize(Vector2f(4.f,6.f));
}
void Canne::input(float power){
    range=100*power;
    trotation=-(1/power);
}
void Canne::update(std::vector<Banc> poisson){
    if (getRotation() >trotation && rotat)
    {
        setRotation(getRotation()-0.01f);
        if (getRotation()<trotation)
        {
            rotat=false;
        }
        
    }

   if (getSize().x<range && max)
   {
        setSize(Vector2f(getSize().x+10,getSize().y));
        setRotation(getRotation()-0.005f);
        if (range-getSize().x<3)
        {
            max=false;
        }
        
   }
   
   if (getRotation()>-1 && getRotation()<1.5f && max==false)
   {
        setRotation(getRotation()+0.005f);
   }
   hammecon.setRotation(getRotation()-0.01f);
   hammecon.setPosition(getPosition().x+cos(getRotation())*getSize().x,getPosition().y+sin(getRotation())*getSize().x);

  for(Banc &b : poisson){
     for (int i = 0; i < b.getFishs().size(); i++)
     {
        if (hammecon.getCollisionBox().check(b.getFishs()[i].getCollisionBox())&& traped!=true)
        {
            
            traped=true;
            catched=new Fish(b.getFish(i));
        }
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
        setSize(getSize().x-5,getSize().y);
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
        catched->setRotation(-getRotation());
        
    }
}
