#include "ModelInstance.h"
#include "../Shaders/ShaderProgram.h"
#include "Model.h"

using namespace GLP;

ModelInstance::ModelInstance(Mesh &model) : model(model) {}

void ModelInstance::render(ShaderProgram &shader) {
  model.bind();
  shader.set("model", modelMatrix);

  glDrawElements((unsigned int)model.shape, model.indexCount, GL_UNSIGNED_INT,
                 0);
  model.unbind();
}

void ModelInstance::refreshModelMatrix() { modelMatrix = glm::mat4(1.f); }


