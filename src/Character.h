#pragma once

#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

#include "Canne.h"

enum State{
    restNotLine=0,
    throwing=1,
    pull=2,
    restLine=3
};

class Perso : public BbopDrawable{
private:
    std::vector<AnimatedSprite> textures;
    State state;
    Vector2f pos;
    bool holding; // holding onto R2

public:
    Perso();
    Perso(Vector2f);
    void Draw(GLint *renderUniform) const override;
    void update();
    void stateUpdate(int);
    int getState();
    Vector2f getPos();
    void setPos(Vector2f);
};
