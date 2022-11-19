#ifndef APP
#define APP

#include <GLFW/glfw3.h>

namespace GLP {

class Scene;
class RenderingContext;
class Camera;

class App {

  GLFWwindow *window;
  Scene * mainScene;
  RenderingContext * renderingContext;
  Camera * camera;


  void init();
  void loop();
  void terminate();

public:
  void start();
};

} // namespace GLP
#endif /*APP*/
