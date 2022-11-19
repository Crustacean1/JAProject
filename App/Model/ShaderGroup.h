#ifndef SHADER_GROUP
#define SHADER_GROUP

#include <list>

namespace GLP {

class ModelInstance;
class ShaderProgram;
class Camera;

class ShaderGroup {
  std::list<ModelInstance *> modelInstances;
  ShaderProgram &program;

public:
  ShaderGroup(ShaderProgram &program);
  void addModelInstance(ModelInstance *instance);
  void useCamera(Camera camera);
  void render();
  unsigned int getShaderId();
};
} // namespace GLP

#endif /*SHADER_GROUP*/
