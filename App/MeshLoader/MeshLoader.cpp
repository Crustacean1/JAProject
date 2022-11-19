#include "MeshLoader.h"
#include "../Model/Model.h"
#include <chrono>
#include <dlfcn.h>
#include <iostream>
#include <math.h>
#include <thread>
#include <vector>

TorusVertexGenerator loadVertexGenerator(const char *filename) {
  void *sharedObject = dlopen(filename, RTLD_LAZY);
  return (TorusVertexGenerator)dlsym(sharedObject, "torusVertexGenerator");
}

TorusIndexGenerator loadIndexGenerator(const char *filename) {
  void *sharedObject = dlopen(filename, RTLD_LAZY);
  return (TorusIndexGenerator)dlsym(sharedObject, "torusIndexGenerator");
}

MeshLoader::MeshLoader() {
  setTorusDimensions(10, 9);
  setTorusResolution(1000, 1000);
  setThreadCount(8);
  loadSharedLibrary(LibraryType::CPP);
}

void MeshLoader::loadSharedLibrary(LibraryType type) {
  switch (type) {
  case LibraryType::CPP:
    vertexGenerator = loadVertexGenerator(CPP_DIRECTORY.c_str());
    indexGenerator = loadIndexGenerator(CPP_DIRECTORY.c_str());
    break;
  case LibraryType::ASM:
    vertexGenerator = loadVertexGenerator(ASM_DIRECTORY.c_str());
    indexGenerator = loadIndexGenerator(ASM_DIRECTORY.c_str());
    break;
  }
}

void MeshLoader::setThreadCount(unsigned int threadCount) {
  this->threadCount = threadCount;
}

void MeshLoader::setTorusDimensions(double torus, double ring) {
  torusSize = torus;
  ringSize = ring;
}

void MeshLoader::setTorusResolution(unsigned int torus, unsigned int ring) {
  torusResolution = torus;
  ringResolution = ring;

  unsigned int targetVertSize = torusResolution * ringResolution * vertexSize;
  unsigned int targetIndSize =
      (torusResolution - 1) * (ringResolution - 1) * indexSize * 2;

  vertices = new float[targetVertSize];
  indices = new unsigned int[targetIndSize];
}

GLP::Mesh *MeshLoader::regenerateMesh() {

  std::vector<std::thread> workers;
  double *threadTimes = new double[threadCount];

  for (int i = 0; i < threadCount; ++i) {

    workers.emplace_back([=]() {
      auto t1 = std::chrono::high_resolution_clock::now();
      vertexGenerator(vertices, i, threadCount, torusSize, ringSize,
                      torusResolution, ringResolution);
      auto t2 = std::chrono::high_resolution_clock::now();
      threadTimes[i] =
          std::chrono::duration<double, std::milli>(t2 - t1).count();
    });
  }

  for (auto &worker : workers) {
    worker.join();
  }

  double max, min, avg;
  max = min = threadTimes[0];
  avg = 0;

  for (int i = 0; i < threadCount; ++i) {
    max = max < threadTimes[i] ? threadTimes[i] : max;
    min = min > threadTimes[i] ? threadTimes[i] : min;
    avg += threadTimes[i];
  }
  avg /= threadCount;

  std::cout << "Min: " << min << std::endl;
  std::cout << "Max: " << max << std::endl;
  std::cout << "Avg: " << avg << std::endl;

  indexGenerator(indices, torusResolution, ringResolution);

  auto mesh = new GLP::Mesh(
      vertices, vertexSize * torusResolution * ringResolution, indices,
      indexSize * (torusResolution - 1) * (ringResolution - 1) * 2,
      GLP::Mesh::Shape::TRIANGLES);

  unsigned char attribs[] = {3, 3};
  mesh->setVertexAttributes(attribs, 2);

  return mesh;
}
