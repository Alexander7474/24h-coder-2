#include "Character.h"

using namespace std;

Perso::Perso(){
    AnimatedSprite s("sprites/1.png", Vector2i(3,1), 0.5);
    textures.push_back(s);
}

void Perso::Draw(GLint *renderUniform) const{
    textures[0].Draw(renderUniform);
}

void Perso::Update(){
    textures[0].update();
}

/*
update en fonction de l'état de l'animation
donc chaque etat = 1 nb de frames
et faut pouvoir changer d'état
donc :
    - une partie qui définit les etats et leur
    nombre de frame
    - une partie qui permet de changer d'état
comme on change d'état en fonction de l'action du
joueur
*/