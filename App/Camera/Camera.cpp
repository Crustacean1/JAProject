#include "Camera.h"
#include "../Shaders/ShaderProgram.h"
#include <glm/gtc/matrix_transform.hpp>

using namespace GLP;

Camera::Camera(float ratio, float fov) : ratio(ratio), fov(fov) {
  computePerspective();
  computeView();
}

void Camera::activate(ShaderProgram &shader) {
  shader.set("perspective", perspective);
  shader.set("view", view);
}

void Camera::setUp(glm::vec3 up) {
  this->up = up;
  computeView();
}

void Camera::setPos(glm::vec3 pos) {
  this->pos = pos;
  computeView();
}

void Camera::setDir(glm::vec3 dir) {
  this->dir = glm::normalize(dir);
  computeView();
}

void Camera::setFov(float fov) {
  this->fov = fov;
  computePerspective();
}

void Camera::setAspectRatio(float ratio) {
  this->ratio = ratio;
  computePerspective();
}

void Camera::computeView() {
  glm::vec3 xAxis, yAxis, zAxis;

  xAxis = glm::normalize(glm::cross(dir, up));
  yAxis = glm::normalize(glm::cross(xAxis, dir));
  zAxis = glm::normalize(glm::cross(yAxis, xAxis));

  view[0] = glm::vec4(xAxis.x, yAxis.x, zAxis.x, 0);
  view[1] = glm::vec4(xAxis.y, yAxis.y, zAxis.y, 0);
  view[2] = glm::vec4(xAxis.z, yAxis.z, zAxis.z, 0);
  view[3] = glm::vec4(0, 0, 0, 1);

  view = view * glm::translate(glm::mat4(1.f), -pos);
}

glm::vec3 Camera::getPos() { return pos; }

glm::vec3 Camera::forwardDir() { return dir; }

glm::vec3 Camera::rightDir() { return glm::normalize(glm::cross(dir, up)); }

glm::vec3 Camera::leftDir() { return glm::normalize(glm::cross(up, dir)); }

glm::vec3 Camera::backwardDir() { return -dir; }

void Camera::computePerspective() {
  perspective = glm::perspective(glm::radians(fov), ratio, 0.1f, 100.f);
}
