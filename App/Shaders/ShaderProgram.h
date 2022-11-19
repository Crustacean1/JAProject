#ifndef SHADER
#define SHADER

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace GLP {

class ShaderCompiler;

class ShaderProgram {
private:
  unsigned int programId;
  ShaderProgram(unsigned int programId);
  friend ShaderCompiler;

public:
  void activate();

  unsigned int getId();

  void set(const char * var, glm::vec3 vec);
  void set(const char * var, glm::vec4 vec);
  void set(const char * var, glm::mat4 vec);
  void set(const char * var, float val);
};

} // namespace GLP

#endif /*SHADER*/
