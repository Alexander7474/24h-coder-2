#include "Game.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

Game::Game() :
    scene(Scene()),
    cam(Camera()),
    map(Map()),
    canne(new Canne(Vector2f(0.f,0.f))),
font(16,"fonts/BigBlueTermPlusNerdFont-Regular.ttf")
{
    cam.setScale(0.4);
    score=0;
    cam.setPosition(map.getSpawnPoints()[0]);
    Perso player(map.getSpawnPoints()[0]);
  canne->setPosition(Vector2f(map.getSpawnPoints()[0].x+45.f,map.getSpawnPoints()[0].y+10.f));
  canneLaunched = false;
  for(int i = 0; i < 13; i++){
    Banc b(i,3.f,0.01f,Vector3i(255,255,255));
    bancs.push_back(b);
  }
  on = false; 
  timer = new TexteBox("timer", &font);
  scoret = new TexteBox("score", &font);
  scoret->setPosition(map.getSpawnPoints()[0]);
  timer->setPosition(Vector2f(map.getSpawnPoints()[0].x,map.getSpawnPoints()[0].y-32));
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

  timer->setTexte(to_string(glfwGetTime()-time).c_str());
  scoret->setTexte(to_string(score).c_str());
  
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

  scene.Draw(*scoret);
  scene.Draw(*timer);

    // Faire le rendue du frame buffer de la fenêtre
    scene.render();
}

void Game::partystarted(){
  if (!gamestarted && !gameend)
  {
    gamestarted=true;
    time=glfwGetTime();
  }
  cerr << glfwGetTime()-time << endl;
  if (glfwGetTime()-time>150)
  {
    gameend=true;
    on = false;

    // reset à partir du main
  }
}

void Game::reset()
{
  
  time = 0;
  score = 0;
  gameend = false;
  gamestarted = false;
  canneLaunched = false;
  on = true;
  
  player.reset();
  canne->reset();

  canne->setPosition(Vector2f(map.getSpawnPoints()[0].x+45.f,map.getSpawnPoints()[0].y+10.f));

  cam.setPosition(map.getSpawnPoints()[0]);
}