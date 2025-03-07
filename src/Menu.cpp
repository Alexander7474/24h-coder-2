#include "Menu.h"
using namespace std;

Menu::Menu() :
    scene(Scene()),
    menu(Sprite("img/menu.png")),
    buttonMenu(Sprite("img/menu_button.png")),
    texte(Sprite("img/text_menu.png")),
    credits(Sprite("img/credits.png"))
{
    credits.setPosition(1920/10-buttonMenu.getSize().x/2, 1080/2);
    credits.setSize(credits.getSize().x*0.3, credits.getSize().y*0.3);

    texte.setSize(texte.getSize().x*0.7, texte.getSize().y*0.7);
    texte.setPosition(1920/2-texte.getSize().x/2, 1080/2-texte.getSize().y);

    buttonMenu.setSize(128*3,60*3);
    buttonMenu.setPosition(1920/2-buttonMenu.getSize().x/2, 1080/2);

    menu.setSize(1920,1080);
    on =  true;
}

void Menu::Draw(){
    scene.Use();
    scene.Draw(menu);
    scene.Draw(texte);
    scene.Draw(buttonMenu);
    scene.Draw(credits);

    scene.render();
}

Menu::~Menu(){}