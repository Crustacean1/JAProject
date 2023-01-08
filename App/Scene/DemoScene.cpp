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
                         "Resources/Shaders/DirectLightShader.fs")),
      torusParams{10, 5, 5, 5, 1} {}

void DemoScene::generate() {

  meshLoader.setParams(torusParams);
  auto torusModel = meshLoader.generateMesh(torusParams);

  GLP::ModelInstance *torusInstance = new GLP::ModelInstance(*torusModel);

  shaderGroups.begin()->clearInstances();
  shaderGroups.begin()->addModelInstance(torusInstance);
}

void DemoScene::init() {

  shaderGroups.emplace_back(basicShader);

  basicShader.set("light.dir", glm::vec3(0, -1, 0));
  basicShader.set("light.color", glm::vec3(1, 1, 1));
  basicShader.set("light.ambient", 0.02);
  basicShader.set("light.diffuse", 0.2);
  basicShader.set("light.specular", 0.4);
  basicShader.set("color", glm::vec4(1, 0, 0, 0));
  camera.setPos(glm::vec3(0, 0, 0));
}

void DemoScene::renderUi() {

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("Torus parameters");
  ImGui::Text("Select parameters for torus generation");

  ImGui::SliderFloat("Torus size", &torusParams.torusSize, 0.0f, 100.f);
  ImGui::SliderFloat("Ring size", &torusParams.ringSize, 0.0f, 100.f);
  ImGui::SliderInt("Torus resolution", &torusParams.torusResolution, 2, 1000);
  ImGui::SliderInt("Ring resolution", &torusParams.ringResolution, 2, 1000);
  ImGui::SliderInt("Thread count", &torusParams.threadCount, 1, 128);

  if (ImGui::Button("Generate")) {
    std::cout << "Hooray, I'm usefull" << std::endl;
    generate();
  }

  ImGui::End();

  ImGui::EndFrame();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
