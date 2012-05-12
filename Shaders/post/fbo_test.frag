#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D sScene;
uniform sampler2D sNormal;
uniform sampler2D sDepth;
uniform sampler2D tex00;
uniform sampler2D tex01;
uniform sampler2D tex02;
uniform sampler2D tex03;
uniform sampler2D tex04;
uniform sampler2D tex05;
uniform sampler2D tex06;
uniform sampler2D tex07;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

void main()
{   
    tmpSaturation = vec4(saturation);
    tmpColor = texture(tex04, oTextureCoord);
    FragColor = brightness*pow(tmpColor,tmpSaturation);
}  