#ifndef TORUS_STATS
#define TORUS_STATS

#include <math.h>

class TorusStats {

public:
  TorusStats(double *times, int n, unsigned int vertexCount)
      : vertexCount(vertexCount) {
    max = min = times[0];
    avg = 0;

    for (int i = 0; i < n; ++i) {
      max = max < times[i] ? times[i] : max;
      min = min > times[i] ? times[i] : min;
      avg += times[i];
    }
    for (int i = 0; i < n; ++i) {
      variance += pow(avg - times[i], 2);
    }
    avg /= n;
  }
  double avg;
  double max;
  double min;
  double variance;
  unsigned int vertexCount;
};

#endif /*TORUS_STATS*/
