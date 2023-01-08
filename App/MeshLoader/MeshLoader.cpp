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

MeshLoader::MeshLoader() : stats(nullptr) {
  loadSharedLibrary(LibraryType::CPP);
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

void MeshLoader::setParams(TorusParams newParams) {
  if (newParams.ringResolution != params.ringResolution ||
      newParams.torusResolution != params.torusResolution) {
    params.ringResolution = newParams.ringResolution;
    params.torusResolution = newParams.torusResolution;

    unsigned int targetVertSize =
        params.torusResolution * params.ringResolution * vertexSize;
    unsigned int targetIndSize =
        (params.torusResolution) * (params.ringResolution) * indexSize * 2;

    vertices = new float[targetVertSize];
    indices = new unsigned int[targetIndSize];
  }
  params.torusSize = newParams.torusSize;
  params.threadCount = newParams.threadCount;
  params.ringSize = newParams.ringSize;
}

GLP::Mesh *MeshLoader::generateMesh(TorusParams params) {
  std::cout << params.torusResolution << "\t" << params.ringResolution << "\t"
            << params.ringSize << "\t" << params.torusSize << "\t"
            << params.threadCount << std::endl;
  std::vector<std::thread> workers;
  double *threadTimes = new double[params.threadCount];
  unsigned int pos = 0;
  unsigned int nextPos = 0;

  for (int i = 0; i < params.threadCount; ++i) {
    nextPos = (i + 1) * params.torusResolution / params.threadCount;

    workers.emplace_back([=]() {
      auto t1 = std::chrono::high_resolution_clock::now();
      std::cout << "thread:\t" << i << "\t" << 2 * M_PI * i / params.threadCount
                << "\t" << nextPos - pos << std::endl;

      vertexGenerator(vertices + pos * params.ringResolution * 8, nextPos - pos,
                      2 * M_PI * pos / params.torusResolution,
                      2 * M_PI / params.torusResolution, params.torusSize,
                      params.ringSize, params.ringResolution);

      auto t2 = std::chrono::high_resolution_clock::now();
      threadTimes[i] =
          std::chrono::duration<double, std::milli>(t2 - t1).count();
    });

    pos = nextPos;
  }

  for (auto &worker : workers) {
    worker.join();
  }

  stats = new TorusStats(threadTimes, params.threadCount, 1);

  indexGenerator(indices, params.torusResolution, params.ringResolution);

  auto mesh = new GLP::Mesh(
      vertices, vertexSize * params.torusResolution * params.ringResolution,
      indices, indexSize * params.torusResolution * params.ringResolution * 2,
      GLP::Mesh::Shape::TRIANGLES);

  unsigned char sizes[] = {3, 3};
  unsigned char padded[] = {4, 4};
  mesh->setVertexAttributes(sizes, padded, 2);

  return mesh;
}
