#version 330
smooth in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Diffuse;
in vec3 Pos;
in vec4 oColor;

layout(location = 0) out vec4 FragColor; // COLOR_ATTACHMENT0
layout(location = 1) out vec4 PositionColor; // COLOR_ATTACHMENT1
layout(location = 2) out vec4 NormalColor; // COLOR_ATTACHMENT2
layout(location = 3) out vec4 RadianceColor; // COLOR_ATTACHMENT3

uniform float Time;

uniform vec3 LightPosition;
uniform vec3 AmbientMaterial;
uniform vec3 SpecularMaterial;
uniform float Shininess;
uniform vec4 iColor;
uniform vec3 Radiance;

uniform sampler2D tex00;

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
    
    FragColor = vec4(color.r,color.g,color.b,color.a);
    FragColor.a = dot(color.rgb, vec3(0.299, 0.587, 0.114));
    NormalColor = vec4(EyespaceNormal,1.0);
    PositionColor = vec4(Pos,1.0);
    RadianceColor = vec4(Radiance,1.0);
    
  //  FragColor = texture(tex00,oTextureCoord);
    
}