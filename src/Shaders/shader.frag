#version 150 core

//in vec3 pass_Color;
uniform float time;
out vec4 out_Color;
in float posz;

in mat3 WorldNormal;
void main(void)
{
      out_Color = vec4(1.0,0,0,1.0);
}