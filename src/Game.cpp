#include "Game.h"

Game::Game() :
    scene(Scene()),
    cam(Camera()),
    map(Map()),
    player(Perso())
{
}

Game::~Game()
{

}

void Game::update()
{
    std::cerr << "L1" << std::endl;
    Draw();
}

void Game::Draw()
{
    scene.Use();
    map.Draw(scene, cam);

    // Faire le rendue du frame buffer de la fenêtre
    scene.render();
}