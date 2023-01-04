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

protected:
  Camera &camera;

public:
  Scene(Camera &camera);

  virtual void init() = 0;
  virtual void render() = 0;
  virtual void update() = 0;
};

} // namespace GLP

#endif /*SCENE*/
