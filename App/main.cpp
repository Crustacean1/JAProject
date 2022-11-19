#include <glad/glad.h>
#include "App/App.h"
#include <iostream>

class GuiData {
public:
  int verticalRingResolution = 10;
  int horizontalRingResolution = 5;
  float outerCircumference = 10;
  float innerCircumference = 2;
};

GuiData torusData;

/*
void initializeGui(GLFWwindow *window) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 420");
}

void startNewGuiFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void defineGui() {
  ImGui::Begin("Torus generation menu");
  ImGui::SliderInt("Vertical ring resolution",
                   &torusData.verticalRingResolution, 1, 100);
  ImGui::SliderInt("Horizontal ring resolution",
                   &torusData.horizontalRingResolution, 1, 100);
  ImGui::SliderFloat("Outer circumference", &torusData.outerCircumference, 0.1f,
                     100.0f);
  ImGui::SliderFloat("Inner circumference", &torusData.innerCircumference, 0.1f,
                     100.0f);
  ImGui::Button("Regenerate torus");
  ImGui::End();
}

void renderGui() {
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void cleanUpGui() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
}*/

int main() {
  GLP::App app;
  app.start();
}
