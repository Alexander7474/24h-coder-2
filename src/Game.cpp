#include "Game.h"

Game::Game() :
    scene(Scene()),
    cam(Camera()),
    map(Map()),
    player(Perso())
{
    cam.setScale(0.25);
    cam.setPosition(map.getSpawnPoints()[0]);
    player.setPos(map.getSpawnPoints()[0]);
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

    

    scene.Draw(player);

    // Faire le rendue du frame buffer de la fenêtre
    scene.render();
}