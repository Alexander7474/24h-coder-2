#include "Character.h"

using namespace std;

Perso::Perso(){
    AnimatedSprite stateRestNotLine("assets/sprite/perso/idle/tileset.png", Vector2i(6,1), 0.5);
    textures.push_back(stateRestNotLine);

    AnimatedSprite stateThrowing("assets/sprite/perso/launch/tileset.png", Vector2i(6,1), 0.7);

    textures.push_back(stateThrowing);

    AnimatedSprite statePull("assets/sprite/perso/pull/tileset.png", Vector2i(2,1), 0.5);
    textures.push_back(statePull);

    AnimatedSprite stateRestLine = statePull;
    
    textures.push_back(stateRestLine);

    state = restNotLine;
  holding = false;
}

Perso::Perso(Vector2f position){
    pos = position;
    
    AnimatedSprite stateRestNotLine("assets/sprite/perso/idle/tileset.png", Vector2i(6,1), 0.5);
    stateRestNotLine.setPosition(pos);
    textures.push_back(stateRestNotLine);
    
    AnimatedSprite stateThrowing("assets/sprite/perso/launch/tileset.png", Vector2i(6,1), 0.7);
    stateThrowing.setPosition(pos);
    textures.push_back(stateThrowing);
    
    AnimatedSprite statePull("assets/sprite/perso/pull/tileset.png", Vector2i(2,1), 0.5);
    statePull.setPosition(pos);
    textures.push_back(statePull);
    
    AnimatedSprite stateRestLine = stateRestNotLine;
    stateRestLine.setPosition(pos);
    textures.push_back(stateRestLine);
    
    state = restNotLine;
}

void Perso::Draw(GLint *renderUniform) const{
    textures[state].Draw(renderUniform);
}

void Perso::update(){
    int axiscount;
    if(glfwJoystickPresent(GLFW_JOYSTICK_1)){
      const float *axis = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axiscount);
      if(!holding && axis[5]>-0.9){
          holding = true;
          if(getState() == restNotLine){
              state = throwing;
              // charging bar !!!
              // add the rest of the code to throw the line
              // this is just the animation of the player throwing the line
          }
          if(getState() == restLine){
            state = pull;
          }
      }

      bool i = textures[state].update();
      if (i && state == throwing){
          state = restLine;
      }
      if(holding && axis[5] == -1){
        holding = false;
        if(state == pull){
        state = restLine;
      }
    }
  }
}

void Perso::stateUpdate(int i){
    if (i == 0) state = restNotLine;
    if (i == 1) state = throwing;
    if (i == 2) state = pull;
    if (i == 3) state = restLine;
}

int Perso::getState(){
    return(state);
}

Vector2f Perso::getPos(){
    return(pos);
}

void Perso::setPos(Vector2f position){
    pos = position;
    textures[0].setPosition(pos);
    textures[1].setPosition(pos);
    textures[2].setPosition(pos);
    textures[3].setPosition(pos);
}
