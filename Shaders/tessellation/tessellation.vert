#version 400
layout(location = 0) in vec4 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec2 TextureCoord;
layout(location = 3) in vec4 Color;
layout(location = 20) in float Time;

out vec3 vPosition;

void main()
{
	vPosition = Position.xyz;
} 