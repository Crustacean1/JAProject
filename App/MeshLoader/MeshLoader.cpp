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
  setTorusDimensions(10, 4);
  setTorusResolution(20, 20);
  setThreadCount(8);
  loadSharedLibrary(LibraryType::ASM);
}

void MeshLoader::loadSharedLibrary(LibraryType type) {
  const char *source;
  switch (type) {
  case LibraryType::CPP:
    source = CPP_DIRECTORY.c_str();
    break;
  case LibraryType::ASM:
    source = ASM_DIRECTORY.c_str();
    break;
  }
  std::cout << "Loading: " << source << std::endl;
  vertexGenerator = loadVertexGenerator(source);
  indexGenerator = loadIndexGenerator(CPP_DIRECTORY.c_str());
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
      (torusResolution) * (ringResolution)*indexSize * 2;

  vertices = new float[targetVertSize];
  indices = new unsigned int[targetIndSize];
}

GLP::Mesh *MeshLoader::regenerateMesh() {

  std::vector<std::thread> workers;
  double *threadTimes = new double[threadCount];
  unsigned int pos = 0;
  unsigned int nextPos = 0;

  for (int i = 0; i < threadCount; ++i) {
    nextPos = (i + 1) * torusResolution / threadCount;

    workers.emplace_back([=]() {
      auto t1 = std::chrono::high_resolution_clock::now();

      vertexGenerator(vertices + pos * ringResolution * 8, nextPos - pos,
                      2 * M_PI * i / threadCount, 2 * M_PI / torusResolution,
                      torusSize, ringSize, ringResolution);

      auto t2 = std::chrono::high_resolution_clock::now();
      threadTimes[i] =
          std::chrono::duration<double, std::milli>(t2 - t1).count();
    });

    pos = nextPos;
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

  for (int i = 0; i < 00; ++i) {
    std::cout << vertices[i * 8] << "\t" << vertices[i * 8 + 1] << "\t"
              << vertices[i * 8 + 2] << "\t" << vertices[i * 8 + 3] << "\t"
              << vertices[i * 8 + 4] << "\t" << vertices[i * 8 + 5] << "\t"
              << vertices[i * 8 + 6] << "\t" << vertices[i * 8 + 7] << "\n";
  }

  indexGenerator(indices, torusResolution, ringResolution);

  auto mesh =
      new GLP::Mesh(vertices, vertexSize * torusResolution * ringResolution,
                    indices, indexSize * torusResolution * ringResolution * 2,
                    GLP::Mesh::Shape::LINES);

  unsigned char sizes[] = {3, 3};
  unsigned char padded[] = {4, 4};
  mesh->setVertexAttributes(sizes, padded, 2);

  return mesh;
}
