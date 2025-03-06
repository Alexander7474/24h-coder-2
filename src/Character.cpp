#include "Character.h"

using namespace std;

Perso::Perso(){
    AnimatedSprite stateRest("sprites/1.png", Vector2i(3,1), 0.5);
    cerr<<"l7"<<endl;
    textures.push_back(stateRest);
    cerr<<"l9"<<endl;
    AnimatedSprite stateThrowing("sprites/2.png", Vector2i(3,1), 0.5);
    textures.push_back(stateThrowing);
    AnimatedSprite statePull("sprites/3.png", Vector2i(3,1), 0.5);
    textures.push_back(statePull);
    state = rest;
}

Perso::Perso(Vector2f position){
    pos = position;
    AnimatedSprite stateRest("sprites/1.png", Vector2i(3,1), 0.5);
    stateRest.setPosition(pos);
    cerr<<"l7"<<endl;
    textures.push_back(stateRest);
    cerr<<"l9"<<endl;
    AnimatedSprite stateThrowing("sprites/2.png", Vector2i(3,1), 0.5);
    stateThrowing.setPosition(pos);
    textures.push_back(stateThrowing);
    AnimatedSprite statePull("sprites/3.png", Vector2i(3,1), 0.5);
    statePull.setPosition(pos);
    textures.push_back(statePull);
    state = rest;
}

void Perso::Draw(GLint *renderUniform) const{
    textures[state].Draw(renderUniform);
}

void Perso::Update(){
    if (state == rest){
        textures[0].update();
    }
    if (state == throwing){
        textures[1].update();
    }
    if (state == pull){
        textures[2].update();
    }
}

void Perso::stateUpdate(int i){
    if (i == 0) state = rest;
    if (i == 1) state = throwing;
    if (i == 2) state = pull;
}

Vector2f Perso::getPos(){
    return(pos);
}

void Perso::setPos(Vector2f position){
    pos = position;
    textures[0].setPosition(pos);
    textures[1].setPosition(pos);
    textures[2].setPosition(pos);
}