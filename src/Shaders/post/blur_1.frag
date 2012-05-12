#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D sScene;

vec4 tmpSaturation;
#define NUM_SAMPLES 5

void main()
{   int i = 0;
    
    for (i = 0; i<= NUM_SAMPLES; i++) {
    	float step = i * 0.0005;
        tmpColor = texture(sScene, oTextureCoord+step);
	tmpColor += texture(sScene, oTextureCoord-step);
        tmpColor += texture(sScene, vec2(oTextureCoord.x+step,oTextureCoord.y-step));
	tmpColor += texture(sScene, vec2(oTextureCoord.x-step,oTextureCoord.y+step));
    	FragColor += tmpColor;
    }
    FragColor /= i*4;
}