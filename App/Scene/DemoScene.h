#ifndef DEMO_SCENE
#define DEMO_SCENE

#include "../MeshLoader/MeshLoader.h"
#include "../RenderingContext/RenderingContext.h"
#include "../Shaders/ShaderProgram.h"
#include "./Scene.h"

class DemoScene : public GLP::Scene {
  MeshLoader meshLoader;
  std::list<GLP::ShaderGroup> shaderGroups;
  GLP::ShaderProgram basicShader;
  std::chrono::system_clock::time_point prevTime;
  double lightAngle;

  void initUi();
  void renderUi();

public:
  DemoScene(GLP::Camera &camera);

  void init();
  void render();
  void update();
};

#endif /*DEMO_SCENE*/
