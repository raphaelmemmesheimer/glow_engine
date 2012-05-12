#version 330
in vec2 oTextureCoord;
out vec4 FragColor;
uniform float Time;
uniform sampler2D tex01;
vec4 tmpColor;

void main()
{   
    tmpColor = vec4(1.0,0.0,0.0,0.0)*texture(tex01, vec2(oTextureCoord.x+sin(Time*0.1),oTextureCoord.y));
    tmpColor += vec4(0.0,1.0,0.0,0.0)*texture(tex01,vec2(oTextureCoord.x,oTextureCoord.y));
    tmpColor += vec4(0.0,0.0,1.0,0.0)*texture(tex01, vec2(oTextureCoord.x-sin(Time*0.1),oTextureCoord.y));
    FragColor = tmpColor;
}  