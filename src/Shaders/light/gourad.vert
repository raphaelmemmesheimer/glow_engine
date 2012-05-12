#version 330
layout(location = 0) in vec4 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec2 TextureCoord;
layout(location = 3) in vec4 Color;
uniform float Time;

//layout(location = 20) in float Time;

uniform mat4 Projection;
uniform mat4 Modelview;
uniform mat3 NormalMatrix;
uniform vec3 DiffuseMaterial;

out vec3 EyespaceNormal;
out vec2 oTextureCoord;
out vec3 Diffuse;
out vec3 Pos;
out vec4 oColor;

uniform vec3 LightPosition;
uniform vec3 AmbientMaterial;
uniform vec3 SpecularMaterial;
uniform float Shininess;

void main()
{

    EyespaceNormal = NormalMatrix * Normal;
    vec3 N = normalize(EyespaceNormal);
    vec3 L = normalize(LightPosition);
    vec3 Eye = L;
    vec3 H = normalize(L + Eye);
    
    float df = dot(N, L);
    float sf = dot(N, H);
    sf = pow(sf, Shininess);
    
    Diffuse = DiffuseMaterial;
    oColor = vec4(AmbientMaterial + df * Diffuse + sf * SpecularMaterial,1.0);
    oTextureCoord = TextureCoord;
   
    gl_Position =  Projection * Modelview * Position;
    Pos = gl_Position.xyz;

    //oColor = Color;
    
 }