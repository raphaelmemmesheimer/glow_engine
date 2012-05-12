#version 150 core

layout(location = 0) in vec3 iPos;
layout(location = 1) in vec3 iNormal;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;
uniform vec3 DiffuseMaterial;

//uniform mat4 MVP;
uniform float time;
out float posz;

out mat3 WorldNormal;

void main(void)
{
  posz = iPos.z;
  gl_Position = Projection*View*mat4(Model)*vec4(iPos, 1.0);
  WorldNormal = mat3(Model)*iNormal;
     //pass_Color = in_Color;
}