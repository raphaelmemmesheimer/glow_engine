#version 330
// simple perwitt implementation
#define vertical
/*
-1 -1 -1
0 0 0
1 1 1
*/
#define horizontal
/*
-1 0 1
-1 0 1
-1 0 1
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
    tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y-offset));
	tmpColor -= texture(sScene, vec2(oTextureCoord.x,oTextureCoord.y-offset)) ; 
	tmpColor -= texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y-offset));

	tmpColor += texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y+offset));
	tmpColor += texture(sScene, vec2(oTextureCoord.x,oTextureCoord.y+offset)) ; 
	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y+offset));
	#endif

	#ifdef horizontal
    tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y-offset));
	tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y)) ; 
	tmpColor -= texture(sScene, vec2(oTextureCoord.x-offset,oTextureCoord.y+offset));

	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y-offset));
	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y)) ; 
	tmpColor += texture(sScene, vec2(oTextureCoord.x+offset,oTextureCoord.y+offset));
	#endif
    FragColor = tmpColor;
}    