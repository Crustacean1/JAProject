#ifndef CAMERA_CONTROLLER
#define CAMERA_CONTROLLER

namespace GLP {
class RenderingContext;

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
  static void mouseMovementCallback(double x, double y);
  static void keyboardCallback(char c, bool keyDown);
  static void viewportCallback(double x, double y);
};

} // namespace GLP

#endif /*CAMERA_CONTROLLER*/
