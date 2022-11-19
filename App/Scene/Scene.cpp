#include "Scene.h"
#include "../Camera/Camera.h"
#include "../Model/Model.h"
#include "../Model/ModelInstance.h"
#include "../Model/ShaderGroup.h"
#include "../Shaders/ShaderCompiler.h"
#include "../Shaders/ShaderProgram.h"
#include <iostream>
#include <thread>
#include <vector>

using namespace GLP;

Scene::Scene(Camera &camera)
    : camera(camera), basicShader(ShaderCompiler::compileToShaderProgram(
                          "Resources/Shaders/DirectLightShader.vs",
                          "Resources/Shaders/DirectLightShader.fs")) {}

void Scene::init() {

  shaderGroups.emplace_back(basicShader);

  basicShader.set("light.dir", glm::vec3(0, -1, 0));
  basicShader.set("light.color", glm::vec3(1, 1, 1));
  basicShader.set("light.ambient", 0.02);
  basicShader.set("light.diffuse", 0.2);
  basicShader.set("light.specular", 0.4);

  auto torusModel = meshLoader.regenerateMesh();
  ModelInstance *torusInstance = new ModelInstance(*torusModel);

  shaderGroups.begin()->addModelInstance(torusInstance);

  camera.setPos(glm::vec3(0, 0, 5));
  basicShader.set("color", glm::vec4(1, 0, 0, 0));
}

void Scene::render() {
  for (auto group : shaderGroups) {
    group.useCamera(camera);
    group.render();
  }
}

void Scene::update() {
  basicShader.set("light.dir", glm::vec3(cos(lightAngle), sin(lightAngle), 0));
  auto currentTime = std::chrono::system_clock::now();
  double timeDelta = (currentTime - prevTime).count();
  lightAngle += timeDelta / 100000000000000000000.0;
}
