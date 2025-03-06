#pragma once

#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

enum State{
    rest=0,
    throwing=1,
    pull=2
};

class Perso : public BbopDrawable{
private:
    std::vector<AnimatedSprite> textures;
    State state;

public:
    Perso();
    void Draw(GLint *renderUniform) const override;
    void Update();
    void stateUpdate(int);
};