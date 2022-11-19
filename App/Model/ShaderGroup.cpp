#include "ShaderGroup.h"
#include "../Camera/Camera.h"
#include "../Model/ModelInstance.h"
#include "../Shaders/ShaderProgram.h"
#include <iostream>

using namespace GLP;

ShaderGroup::ShaderGroup(ShaderProgram &program) : program(program) {}

void ShaderGroup::addModelInstance(ModelInstance *instance) {
  modelInstances.push_back(instance);
}

void ShaderGroup::useCamera(Camera camera) { camera.activate(program); }

void ShaderGroup::render() {
  for (const auto &model : modelInstances) {
    model->render(program);
  }
}

unsigned int ShaderGroup::getShaderId() { return program.getId(); }
