#include <glad/glad.h>
#include "RenderingContext.h"
#include "GLFW/glfw3.h"
#include <stdexcept>

using namespace GLP;

void RenderingContext::windowResizeCallback(GLFWwindow *window, int width,
                                            int height) {
  glViewport(0, 0, width, height);
}

RenderingContext::RenderingContext(int width, int height)
    : width(width), height(height) {}

void RenderingContext::initializeContext() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);

  if (window == NULL) {
    glfwTerminate();
    throw std::runtime_error("Failed to create GLFW window");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    throw std::runtime_error("Failed to initialize GLAD");
  }

  glViewport(0, 0, width, height);

  glfwSetFramebufferSizeCallback(window, windowResizeCallback);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glLineWidth(2.f);
  glPointSize(5.f);
  glEnable(GL_DEPTH_TEST);
}

void RenderingContext::swapBuffers() {
  glfwSwapBuffers(window);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderingContext::pollEvents() {
  glfwPollEvents();
  for (const auto &callback : keyboardCallbacks) {
    callback(window);
  }
}

bool RenderingContext::shouldClose() { return glfwWindowShouldClose(window); }

void RenderingContext::addMouseMovementCallback(void (*callback)(GLFWwindow *,
                                                                 double,
                                                                 double)) {
  glfwSetCursorPosCallback(window, callback);
}

void RenderingContext::addKeyboardCallback(
    std::function<void(GLFWwindow *)> callback) {
  keyboardCallbacks.push_back(callback);
}
