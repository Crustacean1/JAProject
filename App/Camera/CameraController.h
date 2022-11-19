#ifndef CAMERA_CONTROLLER
#define CAMERA_CONTROLLER

#include <GLFW/glfw3.h>

namespace GLP {
class Camera;

class CameraController {
  static Camera *camera;

  static double yAxisAngle;
  static double xAxisAngle;

  static double prevMouseX;
  static double prevMouseY;

public:
  static float speed;
  static float sensitivity;

  static void setCamera(Camera *camera);
  static void mouseMovementCallback(GLFWwindow *window, double x, double y);
  static void keyboardCallback(GLFWwindow *window);
};

} // namespace GLP

#endif /*CAMERA_CONTROLLER*/
