#include "TorusGenerator.h"
#include "math.h"
#include <immintrin.h>

const unsigned int VERTEX_SIZE = 8;

float ones[4] = {1, 1, 1, 1};
float zeros[4] = {0, 0, 0, 0};

__m128 oneVector = _mm_loadu_ps(ones);
__m128 zeroVector = _mm_loadu_ps(zeros);

void torusVertexGenerator(float *vertices, unsigned int stepCount,
                          float startAngle, float angleStep, float torusSize,
                          float ringSize, unsigned int ringResolution) {

  float ringAngle = 0;
  float ringAngleDelta = 2 * M_PI / ringResolution;

  float torusDirection[4] = {cos(startAngle), sin(startAngle), cos(startAngle),
                             sin(startAngle)};
  float ringDirection[4] = {1, 0, 1, 0};

  float torusDelta[4] = {cos(angleStep), -sin(angleStep), sin(angleStep),
                         cos(angleStep)};

  float ringDelta[4] = {cos(ringAngleDelta), -sin(ringAngleDelta),
                        sin(ringAngleDelta), cos(ringAngleDelta)};

  __m256 torusSizeVector =
      _mm256_set_ps(0, 0, 0, 0, 0, torusSize, 0, torusSize);
  __m256 ringSizeVector =
      _mm256_set_ps(1, 1, 1, 1, 0, ringSize, ringSize, ringSize);

  __m128 torusPositionMatrix = _mm_load_ps(torusDirection);
  __m128 torusPositionDeltaMatrix = _mm_loadu_ps(torusDelta);

  __m128 ringPositionMatrix = _mm_load_ps(ringDirection);
  __m128 ringPositionDeltaMatrix = _mm_loadu_ps(ringDelta);

  __m128 buffer;

  for (int i = 0; i < stepCount; ++i) {

    buffer = _mm_mul_ps(torusPositionMatrix, torusPositionDeltaMatrix);

    torusPositionMatrix = _mm_hadd_ps(buffer, buffer);

    __m128 torusDirectionVector =
        _mm_shuffle_ps(torusPositionMatrix, torusPositionMatrix, 0b11010100);

    torusDirectionVector =
        _mm_blend_ps(torusDirectionVector, oneVector, 0b1010);

    for (int j = 0; j < ringResolution; ++j) {
      buffer = _mm_mul_ps(ringPositionMatrix, ringPositionDeltaMatrix);

      ringPositionMatrix = _mm_hadd_ps(buffer, buffer);

      __m128 ringDirectionVector =
          _mm_shuffle_ps(ringPositionMatrix, ringPositionMatrix, 0b01000100);

      __m256 vertex =
          _mm256_setr_m128(ringDirectionVector, ringDirectionVector);

      vertex = _mm256_mul_ps(vertex, ringSizeVector);
      vertex = _mm256_add_ps(vertex, torusSizeVector);
      vertex = _mm256_mul_ps(
          vertex, _mm256_setr_m128(torusDirectionVector, torusDirectionVector));

      _mm256_storeu_ps(vertices, vertex);

      vertices += 8;
      ringAngle += ringAngleDelta;
    }
    startAngle += angleStep;
  }
}

void torusIndexGenerator(unsigned int *indices, unsigned int torusResolution,
                         unsigned int ringResolution) {
  for (int i = 0; i < torusResolution; ++i) {
    for (int j = 0; j < ringResolution; ++j) {
      int upperLeft = i * ringResolution + j;
      int upperRight = ((i + 1) % torusResolution) * ringResolution + j;
      int lowerLeft = i * ringResolution + ((j + 1) % ringResolution);
      int lowerRight = ((i + 1) % torusResolution) * ringResolution +
                       ((j + 1) % ringResolution);

      *(indices)++ = upperLeft;
      *(indices)++ = upperRight;
      *(indices)++ = lowerRight;

      *(indices)++ = upperLeft;
      *(indices)++ = lowerLeft;
      *(indices)++ = lowerRight;
    }
  }
}
