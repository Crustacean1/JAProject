#include "Scene.h"
#include "../Camera/Camera.h"
#include "../Model/Model.h"
#include "../Model/ModelInstance.h"
#include "../Model/ShaderGroup.h"
#include "../Shaders/ShaderCompiler.h"
#include "../Shaders/ShaderProgram.h"
#include <iostream>
#include <thread>
#include <vector>

using namespace GLP;

Scene::Scene(Camera &camera) : camera(camera) {}
