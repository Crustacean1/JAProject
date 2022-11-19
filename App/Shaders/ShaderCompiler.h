#ifndef SHADER_COMPILER
#define SHADER_COMPILER

#include <glad/glad.h>

namespace GLP {

class ShaderProgram;

class ShaderCompiler {
    static constexpr unsigned int LOG_BUFFER_SIZE = 512;
    static char logBuffer[LOG_BUFFER_SIZE];

  static unsigned int compileShader(unsigned int programId, unsigned int shaderType, const char *shaderSource);
  static char *  readFile(const char * filename);

public:
  static ShaderProgram
  compileToShaderProgram(const char *vertexShader,
                         const char *fragmentShader = nullptr,
                         const char *geometricShader = nullptr);
  ~ShaderCompiler();

private:
};

} // namespace GLP
#endif // !SHADER_COMPILER
