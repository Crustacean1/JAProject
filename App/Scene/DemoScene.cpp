#include "DemoScene.h"
#include "../Camera/Camera.h"
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_glfw.h"
#include "../ImGui/imgui_impl_opengl3.h"
#include "../Model/Model.h"
#include "../Model/ModelInstance.h"
#include "../Model/ShaderGroup.h"
#include "../Shaders/ShaderCompiler.h"
#include "../Shaders/ShaderProgram.h"
#include <iostream>
#include <thread>
#include <vector>

DemoScene::DemoScene(GLP::Camera &camera)
    : Scene(camera), basicShader(GLP::ShaderCompiler::compileToShaderProgram(
                         "Resources/Shaders/DirectLightShader.vs",
                         "Resources/Shaders/DirectLightShader.fs")) {}

void DemoScene::initUi() {}

void DemoScene::init() {

  shaderGroups.emplace_back(basicShader);

  basicShader.set("light.dir", glm::vec3(0, -1, 0));
  basicShader.set("light.color", glm::vec3(1, 0.4, 0.2));
  basicShader.set("light.ambient", 0.02);
  basicShader.set("light.diffuse", 0.2);
  basicShader.set("light.specular", 0.4);

  auto torusModel = meshLoader.regenerateMesh();
  GLP::ModelInstance *torusInstance = new GLP::ModelInstance(*torusModel);

  shaderGroups.begin()->addModelInstance(torusInstance);

  camera.setPos(glm::vec3(0, 0, 0));
  basicShader.set("color", glm::vec4(1, 0, 0, 0));

  initUi();
}

void DemoScene::renderUi() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("Torus parameters");
  ImGui::Text("Select parameters for torus generation");

  ImGui::EndFrame();
}

void DemoScene::render() {
  for (auto group : shaderGroups) {
    group.useCamera(camera);
    group.render();
  }
  renderUi();
}

void DemoScene::update() {
  basicShader.set("light.dir", glm::vec3(cos(lightAngle), sin(lightAngle), 0));
  auto currentTime = std::chrono::system_clock::now();
  double timeDelta = (currentTime - prevTime).count();
  lightAngle = -M_PI * 0.5;
  lightAngle += timeDelta / 1000000000.0;
}
