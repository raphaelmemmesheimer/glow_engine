#version 330
layout(location = 0) in vec4 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec2 TextureCoord;
layout(location = 3) in vec4 Color;

//layout(location = 20) in float Time;

uniform mat4 Projection;
uniform mat4 Modelview;
uniform mat3 NormalMatrix;

uniform mat4 TextureMatrix;

out vec3 EyespaceNormal;
out vec2 oTextureCoord;
out vec3 Pos;

void main()
{
    
    //EyespaceNormal = NormalMatrix * Normal;
    gl_Position =  Projection * Modelview * vec4(Position);  
	oTextureCoord = TextureCoord;    
    
 }