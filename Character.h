#pragma once
#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

enum State{
    rest=1,
    throwing=2,
    pull=3
};

class Perso : public BbopDrawable{
private:
    std::vector<AnimatedSprite> textures;

public:
    Perso();
    void Draw(GLint *renderUniform) const override;
    void Update();
};