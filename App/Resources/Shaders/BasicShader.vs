#version 330 core
layout (location = 0) in vec3 pos;

uniform mat4 perspective;
uniform mat4 view;
uniform mat4 model;

void main()
{
  gl_Position = perspective * view * model * vec4(pos.x,pos.y,pos.z,1.0);
}
