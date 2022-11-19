#include "ShaderProgram.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using namespace GLP;

ShaderProgram::ShaderProgram(unsigned int programId) : programId(programId) {}

void ShaderProgram::activate() { glUseProgram(programId); }

unsigned int ShaderProgram::getId() { return programId; }

void ShaderProgram::set(const char *var, glm::vec3 vec) {
  unsigned int locId = glGetUniformLocation(programId, var);
  glUseProgram(programId);
  glUniform3f(locId, vec.x, vec.y, vec.z);
}
void ShaderProgram::set(const char *var, glm::vec4 vec) {
  unsigned int locId = glGetUniformLocation(programId, var);
  glUseProgram(programId);
  glUniform4f(locId, vec.x, vec.y, vec.z, vec.w);
}
void ShaderProgram::set(const char *var, glm::mat4 mat) {
  unsigned int locId = glGetUniformLocation(programId, var);
  glUseProgram(programId);
  glUniformMatrix4fv(locId, 1, GL_FALSE, glm::value_ptr(mat));
}

void ShaderProgram::set(const char *var, float val) {
  unsigned int locId = glGetUniformLocation(programId, var);
  glUseProgram(programId);
  glUniform1f(locId, val);
}
