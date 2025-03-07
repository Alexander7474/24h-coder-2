#include "Menu.h"
using namespace std;

Menu::Menu() :
    scene(Scene()),
    menu(Sprite("img/menu.png")),
    buttonMenu(Sprite("img/menu_button.png"))
{
    buttonMenu.setSize(360,240);
    buttonMenu.setPosition(1920/2-buttonMenu.getSize().x/2, 1080/2-buttonMenu.getSize().y/2);
    menu.setSize(1920,1080);
    on =  true;
}

void Menu::Draw(){
    scene.Use();
    scene.Draw(menu);
    scene.Draw(buttonMenu);

    scene.render();
}

Menu::~Menu(){}