#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

uniform sampler2D s;
uniform sampler2D s1;

void main()
{   
	
	FragColor = texture(s,oTextureCoord);
    //FragColor += texture2dProj(s, oTextureCoord); //
}