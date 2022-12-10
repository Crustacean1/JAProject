#include "TorusGenerator.h"
#include "math.h"
#include <immintrin.h>

const unsigned int VERTEX_SIZE = 8;

float ones[4] = {1, 1, 1, 1};
float zeros[4] = {1, 1, 1, 1};

__m128 oneVector = _mm_loadu_ps(ones);
__m128 zeroVector = _mm_loadu_ps(zeros);

void torusVertexGenerator(float *vertices, unsigned int stepCount,
                          float startAngle, float angleStep, float torusSize,
                          float ringSize, unsigned int ringResolution) {

  float ringAngle = 0;
  float ringAngleDelta = 2 * M_PI / ringResolution;

  float torusDirection[4] = {cos(startAngle), 1, sin(startAngle), 1};
  float ringDirection[4] = {1, 1, 1, 1};

  float torusDelta[4] = {cos(angleStep), -sin(angleStep), sin(angleStep),
                         cos(angleStep)};
  float ringDelta[4] = {cos(ringAngleDelta), -sin(ringAngleDelta),
                        sin(ringAngleDelta), cos(ringAngleDelta)};

  __m256 torusSizeVector =
      _mm256_set_ps(0, 0, 0, 0, 0, torusSize, 0, torusSize);
  __m256 ringSizeVector =
      _mm256_set_ps(1, 1, 1, 1, 0, ringSize, ringSize, ringSize);

  __m128 torusDeltaVector = _mm_loadu_ps(torusDelta);
  __m128 ringDeltaVector = _mm_loadu_ps(ringDelta);

  __m128 torusDirectionVector = _mm_load_ps(torusDirection);
  __m128 ringDirectionVector = _mm_load_ps(ringDirection);

  for (int i = 0; i < stepCount; ++i) {

    __m128 nextTorusDirectionVector =
        _mm_mul_ps(torusDirectionVector, torusDeltaVector);

    torusDirectionVector = _mm_add_ps(
        nextTorusDirectionVector,
        (__m128)_mm_srli_epi64((__m128i)nextTorusDirectionVector, 32));
    __m128 torusTransformVector =
        _mm_blend_ps(torusDirectionVector, oneVector, 0b0101);

    for (int j = 0; j < ringResolution; ++j) {

      __m256 vertex = _mm256_mul_ps(
          _mm256_setr_m128(torusTransformVector, torusTransformVector),
          torusSizeVector);
      // vertex = _mm256_add_ps(vertex, torusSizeVector);
      //  vertex = _mm256_mul_ps(vertex, torusDirectionVector);
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
