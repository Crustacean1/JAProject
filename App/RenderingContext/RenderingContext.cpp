#include <glad/glad.h>
#include "RenderingContext.h"
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_glfw.h"
#include "../ImGui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

using namespace GLP;

RenderingContext *RenderingContext::mainInstance = nullptr;

void RenderingContext::windowResizeCallback(GLFWwindow *window, int width,
                                            int height) {
  glViewport(0, 0, width, height);
  for (const auto &callback : mainInstance->viewportCallbacks) {
    callback(width, height);
  }
}

void RenderingContext::mouseMovementCallback(GLFWwindow *window, double x,
                                             double y) {
  if (!mainInstance->mouseCaptured) {
    return;
  }

  for (const auto &callback : mainInstance->mouseCallbacks) {
    callback(x, y);
  }
}

void RenderingContext::invokeKeyboardCallbacks(int c) {
  for (const auto &callback : keyboardCallbacks) {
    callback(c, keyHistory[c]);
  }
}

void RenderingContext::checkKeyboard() {
  for (int i = 0; i < 5; ++i) {
    if (glfwGetKey(window, keysToCheck[i]) == GLFW_PRESS) {
      invokeKeyboardCallbacks(keysToCheck[i]);
      keyHistory[keysToCheck[i]] = false;
    } else {
      keyHistory[keysToCheck[i]] = true;
    }
  }
}

RenderingContext::RenderingContext(int width, int height)
    : width(width), height(height) {
  if (mainInstance != nullptr) {
    throw new std::runtime_error("Failed to create RenderingContext instance, "
                                 "there is already one running!");
  }
  mainInstance = this;
  keysToCheck = new int[5];
  keysToCheck[0] = 'A';
  keysToCheck[1] = 'W';
  keysToCheck[2] = 'S';
  keysToCheck[3] = 'D';
  keysToCheck[4] = 256;
}

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
  glfwSetCursorPosCallback(window, mouseMovementCallback);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glLineWidth(2.f);
  glPointSize(5.f);
  glEnable(GL_DEPTH_TEST);
  mouseCaptured = true;

  initializeUi();
}

void RenderingContext::initializeUi() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 420");
}

void RenderingContext::swapBuffers() {
  glfwSwapBuffers(window);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderingContext::pollEvents() {
  glfwPollEvents();
  checkKeyboard();
}

bool RenderingContext::shouldClose() { return glfwWindowShouldClose(window); }

void RenderingContext::toggleMouseInputMode() {
  if (mouseCaptured) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    mouseCaptured = false;
  } else {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    mouseCaptured = true;
  }
}

void RenderingContext::addMouseMovementCallback(
    std::function<void(double, double)> callback) {
  mouseCallbacks.push_back(callback);
}

void RenderingContext::addKeyboardCallback(
    std::function<void(char, bool)> callback) {
  keyboardCallbacks.push_back(callback);
}

void RenderingContext::addViewportCallback(
    std::function<void(double, double)> callback) {
  viewportCallbacks.push_back(callback);
}
