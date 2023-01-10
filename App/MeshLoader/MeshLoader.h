#ifndef MESH_LOADER
#define MESH_LOADER

#include "../Model/Model.h"
#include "../Scene/TorusParams.h"
#include <iostream>

typedef void (*TorusVertexGenerator)(float *vertices, unsigned int steps,
                                     float startAngle, float angleStep,
                                     float torusSize, float ringSize,
                                     unsigned int ringResolution);

typedef void (*TorusIndexGenerator)(unsigned int *indices,
                                    unsigned int torusResolution,
                                    unsigned int ringResolution);

TorusVertexGenerator loadVertexGenerator(const char *filename);
TorusIndexGenerator loadIndexGenerator(const char *filename);

class MeshLoader {

  const std::string CPP_DIRECTORY = "../Cpp/build/libgentorus.so";
  const std::string ASM_DIRECTORY = "../Asm/libgentorus.so";

  const unsigned int vertexSize = 8;
  const unsigned int indexSize = 3;

  float *vertices;
  unsigned int *indices;

  TorusParams params;
  double time;

  TorusVertexGenerator vertexGenerator;
  TorusIndexGenerator indexGenerator;

public:
  enum class LibraryType : unsigned char { ASM, CPP };

  void loadSharedLibrary(LibraryType type);

  void setParams(TorusParams params);

  double getLatestGenerationTime();

  GLP::Mesh *generateMesh(TorusParams torusParams);
  double getTime();

  MeshLoader();
};

#endif /*MESH_LOADER*/
