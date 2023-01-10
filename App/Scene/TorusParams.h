#ifndef TORUS_PARAMS
#define TORUS_PARAMS

class TorusParams {
public:
  int ringResolution;
  int torusResolution;

  float ringSize;
  float torusSize;

  int threadCount;

  char * type;
};

#endif /*TORUS_PARAMS*/
