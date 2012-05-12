#version 330

layout(location = 0) in vec4 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec2 TextureCoord;
layout(location = 3) in vec4 Color;

uniform float Time;

//layout(location = 20) in float Time;

uniform mat4 Projection;
uniform mat4 Modelview;
uniform mat3 NormalMatrix;

out vec4 oColor;

void main(){
  gl_Position = Projection*Modelview*Position;
  oColor = Color;
}