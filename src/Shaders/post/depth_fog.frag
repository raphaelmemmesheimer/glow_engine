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
uniform float brightness = 1.0;
uniform int saturation = 1;

uniform vec4 fogColor = vec4(1.0,1.0,1.0,0.0);

vec4 tmpSaturation;

void main()
{   
    tmpSaturation = vec4(saturation);
    tmpColor = texture(sDepth, oTextureCoord);
    vec4 sceneColor = texture(sScene,oTextureCoord);
    FragColor = sceneColor+(pow(tmpColor,vec4(2000))*fogColor);
} 