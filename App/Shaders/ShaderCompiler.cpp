#include "ShaderCompiler.h"
#include "ShaderProgram.h"
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace GLP;

char ShaderCompiler::logBuffer[ShaderCompiler::LOG_BUFFER_SIZE];

unsigned int ShaderCompiler::compileShader(unsigned int programId,
                                           unsigned int shaderType,
                                           const char *shaderFilename) {
  switch (shaderType) {
  case GL_VERTEX_SHADER:
    if (!shaderFilename) {
      throw std::runtime_error("In ShaderCompiler::compileShader: Must specify "
                               "vertex shader filename");
    }
  case GL_FRAGMENT_SHADER:
  case GL_GEOMETRY_SHADER:
    if (!shaderFilename) {
      return 0;
    }
    break;
  default:
    throw std::runtime_error("ShaderCompiler: Invalid shader type defined");
  }

  char *shaderSource = readFile(shaderFilename);

  unsigned int shader = glCreateShader(shaderType);
  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);

  delete[] shaderSource;

  int success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, LOG_BUFFER_SIZE, NULL, logBuffer);
    throw std::runtime_error(std::string("ShaderCompiler, compileShader: ") +
                             std::string("In file: ") +
                             std::string(shaderFilename) + std::string("\n") +
                             std::string(logBuffer));
  }
  glAttachShader(programId, shader);

  return shader;
}

char *ShaderCompiler::readFile(const char *filename) {
  std::ifstream file(filename);

  if (!file) {
    throw std::runtime_error("In ShaderCompiler::readFile: Cannot open file: " +
                             std::string(filename));
  }

  file.seekg(0, file.end);
  unsigned int bufferSize = file.tellg();
  file.seekg(0, file.beg);
  char *data = new char[bufferSize + 1];
  file.read(data, bufferSize);
  data[bufferSize] = 0;
  return data;
}

ShaderProgram
ShaderCompiler::compileToShaderProgram(const char *vertexShaderFile,
                                       const char *fragmentShaderFile,
                                       const char *geometryShaderFile) {
  unsigned int shaderProgram = glCreateProgram();

  unsigned int vertexShader, fragmentShader, geometryShader;

  compileShader(shaderProgram,GL_VERTEX_SHADER, vertexShaderFile);
  compileShader(shaderProgram,GL_FRAGMENT_SHADER, fragmentShaderFile);
  compileShader(shaderProgram,GL_GEOMETRY_SHADER, geometryShaderFile);

  int success;
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, LOG_BUFFER_SIZE, NULL, logBuffer);
    throw std::runtime_error(
        std::string("ShaderCompiler, compileToShaderProgram: ") +
        std::string(logBuffer));
  }

  // glDetachShader(shaderProgram, vertexShader);

  if (fragmentShaderFile) {
    // glDetachShader(shaderProgram, fragmentShader);
  }
  if (geometryShaderFile) {
    // glDetachShader(shaderProgram, geometryShader);
  }

  return ShaderProgram(shaderProgram);
}
