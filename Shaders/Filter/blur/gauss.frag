#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

uniform float time;

vec4 tmpColor;
uniform sampler2D sScene;
uniform sampler2D sDepth;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

//float gaussMask[] = float[](0.002306, 0.003334, 0.010078, 0.063682, 0.841199, 0.063682, 0.010078, 0.003334, 0.002306);//
float gaussMask[] = float[](0.003816, 0.008779, 0.018077, 0.033306, 0.054913, 0.081015, 0.106955, 0.126353, 0.133571, 0.126353, 0.106955, 0.081015, 0.054913, 0.033306, 0.018077, 0.008779, 0.003816);
//float gaussMask[] = float[](1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0, 1.0/9.0);
void main()
{   
	float b = 0.02;
	int maskRadius0.003816, 0.008779, 0.018077, 0.033306, 0.054913, 0.081015, 0.106955, 0.126353, 0.133571, 0.126353, 0.106955, 0.081015, 0.054913, 0.033306, 0.018077, 0.008779, 0.003816 = 10;
	for (int i = -maskRadius; i < mask; i++) {
            vec4 depthColor = pow(texture(sDepth, oTextureCoord),vec4(10000.0));
			float depth = max(max(depthColor.r, depthColor.g), depthColor.b) ;
			//depth = 1.0;
			//depth *= 2;
			FragColor += (gaussMask[i+maskRadius]) * texture(sScene, vec2(oTextureCoord.x+(i*b*depth), oTextureCoord.y));
			FragColor += gaussMask[i+maskRadius] * texture(sScene, vec2(oTextureCoord.x, oTextureCoord.y+(i*b*depth)));
			
			//FragColor = vec4(depth);
			//FragColor *= texture(sScene, oTextureCoord);
	}
	//FragColor -= texture(sScene, oTextureCoord);
	
    
} 