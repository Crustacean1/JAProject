#ifndef MODEL_INSTANCE
#define MODEL_INSTANCE

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace GLP {
class Mesh;
class ShaderProgram;

class ModelInstance {

  glm::mat4 modelMatrix = glm::mat4(1.f);
  Mesh & model; 

public:
  ModelInstance(Mesh & model);

  glm::vec3 position = glm::vec3(0, 0, 0);
  glm::vec3 scaling = glm::vec3(1, 1, 1);
  glm::quat rotation = glm::quat(1, 0, 0, 0);

  void refreshModelMatrix();
  void render(ShaderProgram & shader);
};

} // namespace GLP

#endif /*MODEL_INSTANCE*/
