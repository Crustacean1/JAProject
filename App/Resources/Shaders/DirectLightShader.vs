#version 420 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 norm;

out vec3 vNorm;

uniform mat4 perspective;
uniform mat4 view;
uniform mat4 model;

void main(){
    gl_Position = perspective * view * model * vec4(pos,1);
    vec4 tmp =  model * vec4(norm,0);
    vNorm = vec3(tmp.x,tmp.y,tmp.z);
}
