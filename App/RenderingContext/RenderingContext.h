#ifndef RENDERING_CONTEXT
#define RENDERING_CONTEXT

#include <GLFW/glfw3.h>
#include <list>
#include <functional>

namespace GLP {

class RenderingContext {
  static void windowResizeCallback(GLFWwindow *window, int width, int height);

  GLFWwindow *window;

  std::list<std::function<void(GLFWwindow*)>> keyboardCallbacks;

public:
  const int width;
  const int height;

  RenderingContext(int width, int height);

  void addMouseMovementCallback(void (*mousecallback)(GLFWwindow *,double,double));
  void addKeyboardCallback(std::function<void(GLFWwindow*)> callback);

  void initializeContext();

  void swapBuffers();

  void pollEvents();

  bool shouldClose();
};
} // namespace GLP

#endif /*RENDERING_CONTEXT*/
