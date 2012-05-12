#version 330
smooth in vec3 EyespaceNormal;
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

uniform sampler2D s;
uniform sampler2D s1;

uniform bool uUseTexture;
uniform sampler2D uTex;

void main()
{
	vec3 n = normalize(EyespaceNormal);

	//  Calculate vertex color (vertex color * texture color)
	vec4 color = oColor;

	// Ambient term
	vec4 ambient = vec4(AmbientMaterial,1.0);

	// Diffuse term
	vec3 lightDir = normalize(LightPosition.xyz - Pos);
	float NdotL = abs(dot(n, lightDir));
	vec4 diffuse_ = color * vec4(Diffuse,1.0) * NdotL;

	// Specular term
	vec3 rVector = normalize(2.0 * n * dot(n, lightDir) - lightDir);
	vec3 viewVector = normalize(-Pos);
	float RdotV = dot(rVector, viewVector);
	vec4 specular = vec4(0.0);
	if(RdotV > 0.0)
		specular = vec4(0.4, 0.4, 0.4, 1.0) * vec4(SpecularMaterial,1.0) * pow(RdotV, 20.0);

	FragColor = ambient + diffuse_ + specular;
}