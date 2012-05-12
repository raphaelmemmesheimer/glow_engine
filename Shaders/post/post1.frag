#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

uniform float time;

vec4 tmpColor;
uniform sampler2D sScene;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

void main()
{   
    tmpSaturation = vec4(saturation);
    tmpColor = texture(sScene, oTextureCoord);
    FragColor = brightness*pow(tmpColor,tmpSaturation);
}