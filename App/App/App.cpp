#include "../Scene/DemoScene.h"
#include "App.h"
#include "../Camera/Camera.h"
#include "../Camera/CameraController.h"
#include "../ImGui/imgui.h"
#include "../RenderingContext/RenderingContext.h"
#include <functional>
#include <glad/glad.h>

using namespace GLP;

void App::start() {
  init();
  while (!renderingContext->shouldClose()) {
    loop();
  }
  terminate();
}


void App::init() {
  renderingContext = new RenderingContext(800, 600);
  renderingContext->initializeContext();

  camera = new Camera(8.f / 6);
  CameraController::setCamera(camera);

  renderingContext->addMouseMovementCallback(
      CameraController::mouseMovementCallback);
  renderingContext->addKeyboardCallback(CameraController::keyboardCallback);
  renderingContext->addKeyboardCallback(std::bind(&App::toggleCursorMode, this,
                                                  std::placeholders::_1,
                                                  std::placeholders::_2));

  mainScene = new DemoScene(*camera);
  mainScene->init();
}

void App::loop() {
  renderingContext->pollEvents();
  mainScene->update();
  mainScene->render();
  renderingContext->swapBuffers();
}

void App::terminate() {}

void App::toggleCursorMode(char c, bool keyDown) {
  if (c == 0 && keyDown) {
    renderingContext->toggleMouseInputMode();
  }
}
