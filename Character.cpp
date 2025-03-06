#include "Character.h"

using namespace std;

Character::Character()
    : Base(""), character(Texture(""))
{
    state = rest;
}

void Character::Animate(){ // == animate?
    
}

void Character::Draw(GLint *renderUniforms) const{
    character.Draw(renderUniforms);
}

void Character::SetPosition(Vector2f pos){
    position = pos;
}

Vector2f Character::GetPosition(){
    return(position);
}

int main(){
    return(0);
}