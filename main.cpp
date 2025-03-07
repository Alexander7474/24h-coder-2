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
#include "src/Character.h"

#include"src/Canne.h"

#include <BBOP/Graphics.h>

#include "src/banc.h"
#include "src/fish.h"

using namespace std;

int main() {
  
  GLFWwindow * window;
  bbopInit(1920,1080,"name",window);

  Canne cc(Vector2f(250.f,250.f));
  Scene scene(1.0f, Vector3i(255,255,255));
  Banc poisson(30);

  while (!glfwWindowShouldClose(window))
  {


    bbopCleanWindow(window, Vector3i(0,0,0),1.0);
  

    

    scene.Use();
    
    
    if (GLFW_PRESS==GLFW_KEY_Z)
    {
      cc.remonte(); 
    }
    cc.input(5);
    cc.update(poisson);
    poisson.update();
    scene.Draw(cc);
    cc.draw(scene);
    scene.Draw(poisson);
    scene.render();
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
