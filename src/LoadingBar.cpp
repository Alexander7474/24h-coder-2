#include "LoadingBar.h"

using namespace std;

LoadingBar::LoadingBar(){
    frame = 0;
    for (int i = 0; i<7; i++){
        AnimatedSprite A("img/loading_bar.png", Vector2i(7,1), 0.5);
        textures.push_back(A);   
    }
}

LoadingBar::LoadingBar(Vector2f position){
    pos = position;
    frame = 0;
    for (int i = 0; i<7; i++){
        AnimatedSprite A("img/loading_bar.png", Vector2i(7,1), 0.5);
        A.setPosition(pos);
        textures.push_back(A);   
    }
}

void LoadingBar::update(){
    if (frame < 7){
        frame++;
    }
    else frame = 0;
}

void LoadingBar::setFrame(int i){
    frame = i;
}

void LoadingBar::Draw(GLint *renderUniform) const{
    textures[frame].Draw(renderUniform);
}