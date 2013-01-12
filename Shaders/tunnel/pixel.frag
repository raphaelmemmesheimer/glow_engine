#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

uniform float time;
uniform sampler2D sScene;
uniform int pixelCount = 100;

void main()
{   
	vec2 tc = floor(oTextureCoord* pixelCount*sin(time))/(pixelCount*sin(time));
    FragColor = texture(sScene, tc);
}  
