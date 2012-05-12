#version 330
in vec4 oColor;
out vec4 FragColor;

uniform vec4 iColor;

void main(){
	FragColor.rgb = iColor.rgb;//vec4(1.0,0.0,0.0,1.0);
	FragColor.a = dot(FragColor.rgb, vec3(0.299, 0.587, 0.114));
}