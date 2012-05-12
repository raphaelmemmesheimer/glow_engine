#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D s1;
uniform sampler2D s2;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

void main()
{   
    float step = 0.01;
    int i = 0;
    float tmp = 0.0; 
    for (i = 0; i<= 10; i++) {
      tmp += step;
      float tmp2 = 2*tmp;
      tmp2++; 
      tmpColor = texture(s, ((tmp+oTextureCoord)/tmp2));
      FragColor += tmpColor;
    }
    FragColor /= i;
}  