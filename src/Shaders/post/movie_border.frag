#version 330
in vec2 oTextureCoord;

out vec4 FragColor;

vec4 tmpColor;
uniform sampler2D sScene;
uniform float height = 0.2; // size of horizontal black border
uniform vec4 borderColor = vec4(0.0); // default black
uniform float time;

void main()
{   
    if (oTextureCoord.y > height && oTextureCoord.y < (1.0-height))
       tmpColor = texture(sScene, oTextureCoord);
	else
		tmpColor = vec4(borderColor);
    FragColor = tmpColor;
} 