#version 330
// simple sobel implementation
#define vertical
/*
-3 -10 -3
0 0 0
3 10 3
*/
#define horizontal
/*
-3 0 3
-10 0 10
-3 0 3
*/

in vec2 oTextureCoord;
uniform float Time;

out vec4 FragColor;
uniform sampler2D sScene;



void main()
{   
   float offset = 0.001;
   vec4 tmpColor;
    #ifdef vertical
    tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y-offset)) *3;
	tmpColor -= texture(sScene, vec2(oTextureCoord.x,oTextureCoord.y-offset)) * 10; 
	tmpColor -= texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y-offset))*3;

	tmpColor += texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y+offset)) * 3;
	tmpColor += texture(sScene, vec2(oTextureCoord.x,oTextureCoord.y+offset)) * 10; 
	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y+offset)) *3;
	#endif

	#ifdef horizontal
    tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y-offset))*3;
	tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y)) * 10; 
	tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y+offset))*3;

	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y-offset))*3;
	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y)) * 10; 
	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y+offset))*3;
	#endif
    FragColor = tmpColor;
}   