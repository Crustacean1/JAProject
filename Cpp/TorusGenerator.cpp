#include "TorusGenerator.h"
#include "math.h"
#include <immintrin.h>
#include <iostream>

const unsigned int VERTEX_SIZE = 8;

float *ringPositions;

void ringTableGenerator(unsigned int ringResolution) {
  ringPositions = new float[ringResolution * 8];
  auto ptr = ringPositions;
  double angle;

  for (int i = 0; i < ringResolution; ++i) {
    angle = 2 * M_PI * i / ringResolution;
    *(ptr++) = cos(angle);
    *(ptr++) = sin(angle);
    *(ptr++) = cos(angle);
    *(ptr++) = 0;

    *(ptr++) = cos(angle);
    *(ptr++) = sin(angle);
    *(ptr++) = cos(angle);
    *(ptr++) = 0;
  }
}

void torusVertexGenerator(float *vertices, unsigned int threadNo,
                          unsigned int threadCount, float torusSize,
                          float ringSize, unsigned int torusResolution,
                          unsigned int ringResolution) {

  float torusAngle = 2 * M_PI * threadNo / threadCount;
  float torusAngleStep = 2 * M_PI / torusResolution;
  float ringAngle;

  unsigned int startPosition = threadNo * torusResolution / threadCount;
  unsigned int endPosition = (threadNo + 1) * torusResolution / threadCount;
  unsigned int stepCount = endPosition - startPosition;

  float *ptr = vertices + startPosition * ringResolution * VERTEX_SIZE;

  float outerX, outerY, outerZ;

  float torusSizeVector[] = {torusSize, 0, torusSize, torusSize, 0, 0, 0, 0};
  float ringSizeVector[] = {ringSize, ringSize, ringSize, ringSize, 1, 1, 1, 1};
  float torusDirectionVector[] = {0, 0, 0, 0, 0, 0, 0, 0};

  __m256 torusSizeFactor = _mm256_loadu_ps(torusSizeVector);
  __m256 ringSizeFactor = _mm256_loadu_ps(ringSizeVector);

  for (int i = 0; i < stepCount; ++i, torusAngle += torusAngleStep) {
    torusDirectionVector[0] = torusDirectionVector[4] = cos(torusAngle);
    torusDirectionVector[1] = torusDirectionVector[5] = 1;
    torusDirectionVector[2] = torusDirectionVector[6] = sin(torusAngle);

    __m256 torusDirection = _mm256_loadu_ps(torusDirectionVector);

    for (int j = 0; j < ringResolution; ++j) {
      __m256 ringPosition = _mm256_loadu_ps(ringPositions + j * 8);
      __m256 vertex = _mm256_mul_ps(ringPosition, ringSizeFactor);
      vertex = _mm256_add_ps(vertex, torusSizeFactor);
      vertex = _mm256_mul_ps(vertex, torusDirection);
      _mm256_storeu_ps(ptr, vertex);
      ptr += 8;
    }
  }
}

void torusIndexGenerator(unsigned int *indices, unsigned int torusResolution,
                         unsigned int ringResolution) {
  for (int i = 0; i < torusResolution - 1; ++i) {
    for (int j = 0; j < ringResolution - 1; ++j) {
      *(indices)++ = i * ringResolution + j;
      *(indices)++ = (i + 1) * ringResolution + j;
      *(indices)++ = (i + 1) * ringResolution + (j + 1);

      *(indices)++ = i * ringResolution + j;
      *(indices)++ = (i)*ringResolution + j + 1;
      *(indices)++ = (i + 1) * ringResolution + (j + 1);
    }
  }
}
