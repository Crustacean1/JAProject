#ifndef RENDERING_CONTEXT
#define RENDERING_CONTEXT

#include <GLFW/glfw3.h>
#include <functional>
#include <list>

namespace GLP {

class RenderingContext {

  static constexpr double threshold = 500;
  static RenderingContext *mainInstance;

  static void windowResizeCallback(GLFWwindow *window, int width, int height);
  static void mouseMovementCallback(GLFWwindow *window, double x, double y);

  bool keyHistory[257];
  int *keysToCheck;

  void invokeKeyboardCallbacks(int key);
  void checkKeyboard();

  std::list<std::function<void(char, bool)>> keyboardCallbacks;
  std::list<std::function<void(double, double)>> mouseCallbacks;
  std::list<std::function<void(double, double)>> viewportCallbacks;

  bool mouseCaptured;

  GLFWwindow *window;

  void initializeUi();

public:
  const int width;
  const int height;

  RenderingContext(int width, int height);

  void addMouseMovementCallback(std::function<void(double, double)> callback);
  void addKeyboardCallback(std::function<void(char, bool)> callback);
  void addViewportCallback(std::function<void(double, double)> callback);

  void toggleMouseInputMode();

  void initializeContext();

  void swapBuffers();

  void pollEvents();

  bool shouldClose();
};
} // namespace GLP

#endif /*RENDERING_CONTEXT*/
