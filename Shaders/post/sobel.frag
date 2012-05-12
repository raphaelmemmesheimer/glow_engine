#version 330
in vec2 oTextureCoord;
out vec4 FragColor;
uniform float Time;
uniform sampler2D tex00;
vec4 tmpColor;

mat3 g1 = mat3(-1.0, -2.0, -1.0,
            	0.0, 0.0, 0.0,
		        1.0, 2.0, 1.0);

mat3 g2 = mat3( -1.0, 0.0 ,1.0,
            	-2.0, 0.0, 2.0,
		        -1.0, 0.0, 1.0);

void main()
{   
    texture(tex00,oTextureCoord)
    FragColor = ;
}   