/*
 * spriteClass.cpp
 *
 * Ce programme est distribué sous les termes de la Licence Publique
 * Générale GNU, version 3.0, telle que publiée par la Free Software
 * Foundation. Consultez la Licence Publique Générale GNU pour plus de
 * détails.
 *
 * Vous devez avoir reçu une copie de la Licence Publique Générale GNU
 * en même temps que ce programme. Si ce n'est pas le cas, consultez
 * <https://www.gnu.org/licenses/>.
 */

////////////////////////////////////////////////////////////////////
//CECI N'EST QU'UN EXEMPLE POUR TESTER SI BBOP EST BIEN INSTALLER
////////////////////////////////////////////////////////////////////
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <chrono>

#include <BBOP/Graphics.h>

#include "src/Game.h"
#include "src/Menu.h"

using namespace std;

int main() {
  
  GLFWwindow * window;
  bbopInit(1920,1080,"name",window);

  Game game;
  Menu m;
  Scene s;

  Sprite restart("img/restart_button.png");
  restart.setSize(128*3,60*3);
  restart.setPosition(1920/2 - restart.getSize().x/2, 1080/2 - restart.getSize().y/2);

  while (!glfwWindowShouldClose(window))
  {
    // Nettoyage de la fenêtre
    bbopCleanWindow(window, Vector3i(0,0,0),1.0);

    if (m.on)
    {
      m.Draw();
      int buttoncount;
      const unsigned char *button = glfwGetJoystickButtons(GLFW_JOYSTICK_1 , &buttoncount);
      if (GLFW_PRESS==button[0])
      { // A is pressed
        m.on = false;
        game.on = true;
      }
    }
    else if (game.on)
    {
      game.partystarted();
      game.update();
      game.Draw();
    }

    else
    {
      game.Draw();
      
      s.Use();
      s.Draw(restart);
      s.render();
      int buttoncount;
      const unsigned char *button = glfwGetJoystickButtons(GLFW_JOYSTICK_1 , &buttoncount);
      if (GLFW_PRESS==button[0]){ // A is pressed
        game.reset();
      }
    }
        
    // Verfication d'erreur opengl
    bbopErrorCheck();

    // Passage du front buffer pour afficher le rendue opengl sur la fenêtre glfw 
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  
  // Suppression de la fenêtre
  glfwDestroyWindow(window);
  glfwTerminate();
  
  return 0;
}
