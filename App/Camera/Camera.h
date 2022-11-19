#ifndef CAMERA
#define CAMERA

#include <glm/glm.hpp>

namespace GLP {
class ShaderProgram;

class Camera {

  float ratio;
  float fov;

  glm::vec3 up = glm::vec3(0,1,0);
  glm::vec3 dir = glm::vec3(0,0,1);
  glm::vec3 pos = glm::vec3(0,0,0);

  glm::mat4 view;
  glm::mat4 perspective;

  void computeView();
  void computePerspective();

public:
  Camera(float ratio, float fov = 45.f);
  void activate(ShaderProgram &program);

  void setUp(glm::vec3 up);
  void setDir(glm::vec3 up);
  void setPos(glm::vec3 pos);

  glm::vec3 getPos();
  glm::vec3 forwardDir();
  glm::vec3 backwardDir();
  glm::vec3 rightDir();
  glm::vec3 leftDir();

  void setAspectRatio(float ratio);
  void setFov(float fov);
};

} // namespace GLP

#endif /*CAMERA*/
