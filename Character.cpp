#include "Character.h"

using namespace std;

Perso::Perso(){
    AnimatedSprite stateRest("sprites/1.png", Vector2i(3,1), 0.5);
    textures.push_back(stateRest);
    AnimatedSprite stateThrowing("sprites/2.png", Vector2i(3,1), 0.5);
    textures.push_back(stateThrowing);
    AnimatedSprite statePull("sprites/3.png", Vector2i(3,1), 0.5);
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