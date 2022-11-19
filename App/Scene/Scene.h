#ifndef SCENE
#define SCENE

#include "../MeshLoader/MeshLoader.h"
#include "../Shaders/ShaderProgram.h"
#include <chrono>
#include <list>

namespace GLP {
class ShaderGroup;
class ShaderProgram;
class Camera;

class Scene {

  MeshLoader meshLoader;
  std::list<ShaderGroup> shaderGroups;
  Camera &camera;
  ShaderProgram basicShader;
  std::chrono::system_clock::time_point prevTime;
  double lightAngle;

public:
  Scene(Camera &camera);

  void init();
  void render();
  void update();
};

} // namespace GLP

#endif /*SCENE*/
