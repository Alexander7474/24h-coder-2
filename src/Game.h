#pragma once

#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

#include "Character.h"


class Game
{
private :
    Scene scene;
    Camera cam;
    Map map;
    Perso player;

public :
    Game();
    Game(Scene _scene, Camera _cam);
    ~Game();

    void Draw();
    void update();
};