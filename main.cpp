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
#include "include/Character.h"

#include <BBOP/Graphics.h>


using namespace std;

float fast_rand(float min, float max) {
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    seed = (214013 * seed + 2531011); // LCG constants
    return min + (seed >> 16) * (1.0f / 65535.0f) * (max - min); // Scale to [min, max]
}

int main() {
  
  GLFWwindow * window;
  bbopInit(1920,1080,"name",window);
  
  Scene scene(1.0f, Vector3i(255,255,255));
  cerr<<"l42"<<endl;

   // Masquer le curseur de la souris
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
  cerr<<"l45"<<endl;

  // fond 
  RectangleShape rectangle;
  cerr<<"l50"<<endl;

  Perso p;
  cerr<<"l53"<<endl;

  while (!glfwWindowShouldClose(window))
  {
    // Nettoyage de la fenêtre
    bbopCleanWindow(window, Vector3i(0,0,0),1.0);
    cerr<<"l55"<<endl;

    // On 'active' la scene pour donner au shader opengl les variables uniforms
    scene.Use();
    cerr<<"l59"<<endl;

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
      p.stateUpdate(0);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
      p.stateUpdate(1);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
      p.stateUpdate(2);
    }
    cerr<<"l70"<<endl;

    p.Update();
    cerr<<"l73"<<endl;

    scene.Draw(p);
    cerr<<"l76"<<endl;

    // Faire le rendue du frame buffer de la fenêtre
    scene.render();
    
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
