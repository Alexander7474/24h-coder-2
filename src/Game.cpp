#include "Game.h"
#include "Character.h"
#include <iostream>
using namespace std;

Game::Game() :
    scene(Scene()),
    cam(Camera()),
    map(Map()),
    canne(new Canne(Vector2f(0.f,0.f)))
{
    cam.setScale(0.4);
    score=0;
    cam.setPosition(map.getSpawnPoints()[0]);
    Perso player(map.getSpawnPoints()[0]);
  canne->setPosition(Vector2f(map.getSpawnPoints()[0].x+45.f,map.getSpawnPoints()[0].y+10.f));
  canneLaunched = false;
  for(int i = 0; i < 10; i++){
    Banc b(i,3.f,0.01f,Vector3i(255,255,255));
    bancs.push_back(b);
  }
  on = false; 
}

Game::~Game()
{}

void Game::update()
{
    player.setPos(map.getSpawnPoints()[0]);
    player.update();
    for(Banc &b : bancs){
      b.update();
  }
  if(player.getState() == pull){
    canne->remonte();
    if (canne->linesize()>5 && canne->linesize()<12)
    {
      player.stateUpdate(0);
      score+=canne->guetscore();
      delete canne;
      canneLaunched=false;
      canne=new Canne(Vector2f(0.f,0.f));
      canne->setPosition(Vector2f(map.getSpawnPoints()[0].x+45.f,map.getSpawnPoints()[0].y+10.f));
    }
  }
  if(player.getState() == restLine){
    canneLaunched = true;
  }
  if(canneLaunched){
    canne->update(bancs);
    cam.setPosition(canne->hammeconpos());
  }
  
}

void Game::Draw()
{
    scene.Use();
    map.Draw(scene, cam);

    scene.Draw(player);
    for(Banc &b : bancs){
      for(Light &l : b.getFishsLight()){
        scene.addLight(l);
      }
      scene.Draw(b);
    }
    if(canneLaunched)
       scene.Draw(*canne);
       canne->draw(scene);

    // Faire le rendue du frame buffer de la fenêtre
    scene.render();
}

void Game::partystarted(){
  if (!gamestarted)
  {
    gamestarted=true;
    time=glfwGetTime();
  }
  
}