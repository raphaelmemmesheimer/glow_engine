#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

uniform float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D s1;
uniform sampler2D s2;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

vec2 rotate(vec2 coord, float angle){
  return  vec2(((coord.x*cos(angle))-coord.y*sin(angle)),
                 coord.y*cos(angle)+(coord.x*sin(angle)));
}

void main()
{   
    tmpSaturation = vec4(saturation);
    tmpColor = texture(s, texture(s,1-oTextureCoord.xy).xy);
    tmpColor *= sin(oTextureCoord.y*1100); // tv scanlines
    FragColor = brightness*tmpColor*vec4(0.8,1.0,0.8,1.0);
}  