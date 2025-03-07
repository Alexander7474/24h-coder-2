#pragma once

#include <BBOP/Graphics/bbopMathClass.h>
#include <BBOP/Graphics/sceneClass.h>
#include <BBOP/Graphics.h>

class Menu{
    private:
        Sprite menu;
        Sprite buttonMenu;
        Scene scene;
    public:
        Menu();
        bool on;
        void Draw();
        ~Menu();
};