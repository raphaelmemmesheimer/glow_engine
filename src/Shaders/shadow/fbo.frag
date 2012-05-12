#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D sScene;
uniform sampler2D sNormal;
uniform sampler2D sDepth;
uniform sampler2D sRadiance;
uniform sampler2DShadow sShadowMap;
uniform float brightness = 1.0;
uniform int saturation = 1;
in vec4 oShadowProjection;

vec4 tmpSaturation;

void main()
{   
    tmpSaturation = vec4(1000);
    vec3 coord = oShadowProjection.xyz/oShadowProjection.w;
    //tmpColor = texture(sShadowMap, coord.xy);
    float rValue;
    float specularItensity;
    if(coord.x >= 0.0 && coord.y >= 0.0 && coord.x <= 1.0 && coord.y <= 1.0 )
    {
		rValue = texture(sShadowMap, coord) < coord.z - 0.001 ? 0.5 : 1.0;
		
		if (rValue == 0.5)
		{
			specularItensity = 0.0;
		}
	} 
    tmpColor = texture(sScene,oTextureCoord);
    //FragColor = tmpColor//*specularItensity;
}  




_______________________________________-



#version 330
layout(location = 0) in vec4 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec2 TextureCoord;

//layout(location = 20) in float Time;

uniform mat4 Projection;
uniform mat4 Modelview;
uniform mat3 NormalMatrix;
uniform vec3 DiffuseMaterial;

out vec3 EyespaceNormal;
out vec2 oTextureCoord;
out vec4 oShadowProjection;
out vec3 Pos;

uniform mat4 lightLookAtMatrix;
uniform mat4 lightProjectionMatrix;
uniform mat4 ShadowMapBias;

void main()
{
    oTextureCoord = TextureCoord;
    oShadowProjection = ShadowMapBias*lightProjectionMatrix*lightLookAtMatrix*vec4(Position);
    EyespaceNormal = NormalMatrix * Normal;
    gl_Position =  Projection * Modelview * vec4(Position);  
 } 