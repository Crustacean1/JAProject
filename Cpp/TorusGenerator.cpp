#include "TorusGenerator.h"
#include "math.h"
#include <iostream>

const unsigned int VERTEX_SIZE = 6;

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

  float outerX;
  float outerY = 0;
  float outerZ;

  for (int i = 0; i < stepCount; ++i, torusAngle += torusAngleStep) {
    outerX = cos(torusAngle);
    outerZ = sin(torusAngle);
    ringAngle = 0;

    for (int j = 0; j < ringResolution;
         ++j, ringAngle = 2 * M_PI * j / ringResolution) {
      *(ptr++) = outerX * torusSize + outerX * cos(ringAngle) * ringSize;
      *(ptr++) = sin(ringAngle) * ringSize;
      *(ptr++) = outerZ * torusSize + outerZ * cos(ringAngle) * ringSize;

      *(ptr++) = outerX * cos(ringAngle);
      *(ptr++) = sin(ringAngle);
      *(ptr++) = outerZ * cos(ringAngle);
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
