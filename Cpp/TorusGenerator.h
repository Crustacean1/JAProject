#ifndef TORUS_GENERATOR
#define TORUS_GENERATOR

extern "C" void torusVertexGenerator(float *vertices, unsigned int threadNo,
                                     unsigned int threadCount, float torusSize,
                                     float ringSize, unsigned int arcResolution,
                                     unsigned int ringResolution);

extern "C" void torusIndexGenerator(unsigned int *indices,
                                    unsigned int torusResolution,
                                    unsigned int ringResolution);

#endif /*TORUS_GENERATOR*/
