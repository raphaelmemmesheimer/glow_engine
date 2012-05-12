#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D sScene;
uniform sampler2D sSceneRed;
uniform sampler2D sSceneCyan;
uniform sampler2D sNormal;
uniform sampler2D sDepth;
uniform sampler2D sRadiance;
uniform sampler2D sShadowMap;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

void main()
{   
    tmpSaturation = vec4(saturation);
    vec4 ColorRed = texture(sSceneRed, oTextureCoord)*vec4(1.0,0.0,0.0,1.0);
    vec4 ColorCyan = texture(sSceneCyan, oTextureCoord)*vec4(.0,1.0,1.0,1.0);;
    tmpColor = texture(sScene, oTextureCoord);
    FragColor = tmpColor*(ColorCyan+ColorRed);
}  