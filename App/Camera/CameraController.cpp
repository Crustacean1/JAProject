#include "CameraController.h"
#include "Camera.h"
#include <iostream>
#include <math.h>

using namespace GLP;

Camera *CameraController::camera = nullptr;

float CameraController::speed = 0.15;
float CameraController::sensitivity = 0.03;

double CameraController::prevMouseX = 0;
double CameraController::prevMouseY = 0;

double CameraController::xAxisAngle = 180;
double CameraController::yAxisAngle = 0;

void CameraController::mouseMovementCallback(GLFWwindow *window, double x,
                                             double y) {
  double deltaX = x - prevMouseX;
  double deltaY = y - prevMouseY;

  // if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
  xAxisAngle -= deltaX * sensitivity;
  yAxisAngle =
      std::min(std::max(yAxisAngle + deltaY * sensitivity, -89.0), 89.0);
  // yAxisAngle = std::min(std::max(yAxisAngle - deltaY *
  // sensitivity,-89.9),89.99);

  double yCos = cos(glm::radians(yAxisAngle));
  double ySin = sin(glm::radians(yAxisAngle));

  double xCos = cos(glm::radians(xAxisAngle));
  double xSin = sin(glm::radians(xAxisAngle));

  camera->setDir(glm::vec3(yCos * xCos, ySin, yCos * xSin));
  //}
  prevMouseX = x;
  prevMouseY = y;
}

void CameraController::keyboardCallback(GLFWwindow *window) {
  if (camera == nullptr) {
    return;
  }
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    camera->setPos(camera->getPos() - (camera->forwardDir() * speed));
  }
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    camera->setPos(camera->getPos() - (camera->backwardDir() * speed));
  }
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    camera->setPos(camera->getPos() + (camera->leftDir() * speed));
  }
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    camera->setPos(camera->getPos() + (camera->rightDir() * speed));
  }
  auto pos = camera->forwardDir();
}

void CameraController::setCamera(Camera *newCamera) { camera = newCamera; }
