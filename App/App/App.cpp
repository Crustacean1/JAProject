#include <glad/glad.h>
#include "App.h"
#include "../Camera/Camera.h"
#include "../Camera/CameraController.h"
#include "../RenderingContext/RenderingContext.h"
#include "../Scene/Scene.h"

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

  mainScene = new Scene(*camera);
  mainScene->init();
}

void App::loop() {
  renderingContext->pollEvents();
  mainScene->update();
  mainScene->render();
  renderingContext->swapBuffers();
}

void App::terminate() {}
