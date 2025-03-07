#pragma once

#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

class LoadingBar : public BbopDrawable{
private:
    std::vector<AnimatedSprite> textures;
    Vector2f pos;
    int frame;

public:
    LoadingBar();
    LoadingBar(Vector2f);
    void update();
    void setFrame(int);
    void Draw(GLint *renderUniform) const override;
};