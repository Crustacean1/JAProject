#version 420 core

in vec3 vNorm;

out vec4 fColor;

struct DirectionalLight{
    vec3 dir;
    vec3 color;
    float ambient;
    float diffuse;
    float specular;
};

uniform DirectionalLight light;

void main(){
    vec3 result = vec3(0,0,0);
    vec3 norm = normalize(vNorm);

    vec3 ambient = light.ambient * light.color;
    vec3 diffuse = max(-dot(light.dir, norm),0) * light.color;
    fColor = vec4(ambient + diffuse,0);
}
