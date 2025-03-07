#pragma once

#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

#include "Character.h"
#include "banc.h"
#include "Canne.h"

class Game
{
private :
    Scene scene;
    Camera cam;
    Map map;
    Perso player;
    std::vector<Banc> bancs;
    Canne *canne;
    bool canneLaunched;
    bool gamestarted,gameend;
    float time;
    int score;
  Font font;
  TexteBox *timer;
  TexteBox *scoret;
public :
    Game();
    ~Game();
    bool on;
    void Draw();
    void update();
    void partystarted();
    void reset();
};
