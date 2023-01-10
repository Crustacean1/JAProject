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

int main() {
  GLP::App app;
  app.start();
}
