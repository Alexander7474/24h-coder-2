#include "Character.h"

using namespace std;

Perso::Perso(){
    AnimatedSprite s("sprites/1.png", Vector2i(3,1), 0.5);
    textures.push_back(s);
    state = rest;
}

void Perso::Draw(GLint *renderUniform) const{
    textures[0].Draw(renderUniform);
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
    else exit(1); // error in Perso::Update
}

void Perso::stateUpdate(int i){
    if (i == 0) state = rest;
    if (i == 1) state = throwing;
    if (i == 2) state = pull;
    else exit(1); // error in Perso::stateUpdate
}

void Perso::brouillon(){

}