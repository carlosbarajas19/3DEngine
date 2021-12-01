#version 430 core 
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 texcoord;

out vec3 fs_color;
out vec2 fs_texcoord;

struct Material 
{
    vec3 ambient;  
    vec3 diffuse;  
    vec3 specular;  
};

struct Light 
{
    vec4 position;
    vec3 ambient;  
    vec3 diffuse;  
    vec3 specular;  
};

uniform Material material;
uniform Light light;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    //ambient
    vec3 ambient = material.ambient * light.ambient;
    //diffuse

    fs_color = ambient;
    fs_texcoord = texcoord;
    gl_Position = projection * view * model * vec4(position, 1.0);
}