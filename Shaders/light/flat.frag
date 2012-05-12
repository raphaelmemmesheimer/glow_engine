#version 330
flat in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Diffuse;
in vec3 Pos;
in vec4 oColor;

out vec4 FragColor;

uniform float Time;

uniform vec3 LightPosition;
uniform vec3 AmbientMaterial;
uniform vec3 SpecularMaterial;
uniform float Shininess;

void main()
{
	
    vec3 N = normalize(EyespaceNormal);
    vec3 L = normalize(LightPosition);
    vec3 Eye = L;
    vec3 H = normalize(L + Eye);
    
    float df = dot(N, L);
    float sf = dot(N, H);
    sf = pow(sf, Shininess);
    

    vec4 colorLight = vec4(AmbientMaterial + df * Diffuse + sf * SpecularMaterial,1.0);

    vec4 color = colorLight;
    
    FragColor = vec4(color.r,color.g,color.b,1.0);

}