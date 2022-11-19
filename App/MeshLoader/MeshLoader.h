#ifndef MESH_LOADER
#define MESH_LOADER

#include "../Model/Model.h"
#include <iostream>

typedef void (*TorusVertexGenerator)(float *vertices, unsigned int threadNo,
                                     unsigned int threadCount, float torusSize,
                                     float ringSize,
                                     unsigned int torusResolution,
                                     unsigned int ringResolution);

typedef void (*TorusIndexGenerator)(unsigned int *indices,
                                    unsigned int torusResolution,
                                    unsigned int ringResolution);

TorusVertexGenerator loadVertexGenerator(const char *filename);
TorusIndexGenerator loadIndexGenerator(const char *filename);

class MeshLoader {

  const std::string CPP_DIRECTORY = "../Cpp/build/libgentorus.so";
  const std::string ASM_DIRECTORY = "../Cpp/build/libgentorus.so";

  const unsigned int vertexSize = 6;
  const unsigned int indexSize = 3;

  float *vertices;
  unsigned int *indices;

  unsigned int threadCount;

  unsigned int torusResolution;
  unsigned int ringResolution;

  double torusSize;
  double ringSize;

  TorusVertexGenerator vertexGenerator;
  TorusIndexGenerator indexGenerator;

public:
  enum class LibraryType : unsigned char { ASM, CPP };

  void loadSharedLibrary(LibraryType type);

  void setTorusDimensions(double torus, double ring);
  void setTorusResolution(unsigned int torus, unsigned int ring);
  void setThreadCount(unsigned int threadCount);

  double getLatestGenerationTime();

  GLP::Mesh *regenerateMesh();

  MeshLoader();
};

#endif /*MESH_LOADER*/
