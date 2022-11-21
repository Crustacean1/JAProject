#ifndef MODEL
#define MODEL

#include <glad/glad.h>

namespace GLP {

class Mesh {
public:
  enum class Shape : int {
    POINTS = GL_POINTS,
    LINES = GL_LINES,
    TRIANGLES = GL_TRIANGLES,
    TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
    QUADS = GL_QUADS
  };

private:
  unsigned int VAO;
  unsigned int EBO;
  unsigned int VBO;

  unsigned int layoutCount;

  unsigned int getPolyCount(Shape shape, unsigned int indexCount);

public:
  Mesh(const float *vertices, unsigned int vertexCout,
       const unsigned int *indices, unsigned int indexCount, Shape shape);

  void setVertexAttributes(const unsigned char *channelSizes,
                           unsigned char *padded, unsigned char channelCount);
  void bind();
  void unbind();

  const unsigned int indexCount;
  const Shape shape;
};
} // namespace GLP

#endif // !MODEL
