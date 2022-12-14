#include "Model.h"
#include <glad/glad.h>
#include <iostream>

using namespace GLP;

Mesh::Mesh(const float *vertices, unsigned vertexCount,
           const unsigned int *indices, unsigned int indexCount, Shape shape)
    : shape(shape), indexCount(indexCount) {

  glGenVertexArrays(1, &VAO);

  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexCount,
               indices, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, vertices,
               GL_STATIC_DRAW);
  glBindVertexArray(0);
}

void Mesh::setVertexAttributes(const unsigned char *size, unsigned char *padded,
                               unsigned char channelCount) {

  float *offset = 0;
  unsigned int stride = 0;

  for (unsigned char i = 0; i < channelCount; ++i) {
    stride += padded[i];
  }

  bind();

  for (unsigned char i = 0; i < channelCount; ++i) {
    glVertexAttribPointer(i, size[i], GL_FLOAT, GL_FALSE,
                          stride * sizeof(float), (void *)offset);
    offset += padded[i];
    glEnableVertexAttribArray(i);
  }
  unbind();
}

void Mesh::bind() { glBindVertexArray(VAO); }

void Mesh::unbind() { glBindVertexArray(0); }
