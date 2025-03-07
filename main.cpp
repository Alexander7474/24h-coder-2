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

#include "src/banc.h"
#include "src/fish.h"

using namespace std;

int main() {
  
  GLFWwindow * window;
  bbopInit(1920,1080,"name",window);
  
  Scene scene(0.0f, Vector3i(255,255,255));

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
  srand(time(NULL));

  Banc b(10, 9.f, 0.01f, Vector3i(135,200,235));
  Banc b2(10, 2.f, 0.01f, Vector3i(235,200,135));
  RectangleShape bg;
  bg.setSize(1920,1080);

  while (!glfwWindowShouldClose(window))
  {

    #ifdef DEBUG 
    system("clear");
    for(string &s: LOGS){
      cout << s << endl;
    }
    cout << "----------------------------------------------------------------" << endl;
    #endif
    // Nettoyage de la fenêtre
    bbopCleanWindow(window, Vector3i(0,0,0),1.0);

    // On 'active' la scene pour donner au shader opengl les variables uniforms
    scene.Use();


    b.update();
    b2.update();
    scene.Draw(bg);
    scene.Draw(b);
    scene.Draw(b2);

    for(Light &l : b.getFishsLight()){
      scene.addLight(l);
    }
    for(Light &l : b2.getFishsLight()){
      scene.addLight(l);
    }

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
