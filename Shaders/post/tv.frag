#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

uniform float time;

vec4 tmpColor;
uniform sampler2D sScene;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

uniform float mixValue = 0.5;
uniform float borderWidth = 80;

uniform vec4 overlayColor = vec4( 0.9, 1.0, 0.9, 1.0);

void main()
{   
    vec4 tmpColor1 = texture(sScene, oTextureCoord);
    tmpColor.rgb = vec3(max(max(tmpColor1.r, tmpColor1.g), tmpColor1.b));
	tmpColor1 *= overlayColor;
	tmpColor *= overlayColor;
	tmpColor.rgb = mix(tmpColor1.rgb, tmpColor.rgb, mixValue);
    //tmpColor = mix(tmpColor, (vec4(abs(sin(oTextureCoord.y*300))) * vec4(1.0, 1.0, 1.0, 1.0)));
	tmpColor *= (vec4(abs(sin(oTextureCoord.y*600))) * vec4(1.0, 1.0, 1.0, 1.0));

	tmpColor *= clamp(vec4((sin(time*10)+borderWidth)*(oTextureCoord.y*oTextureCoord.x)) , vec4(0.0), vec4(1.0)); //bottom left border
	tmpColor *=clamp(vec4((sin(time*20)+borderWidth)*((1-oTextureCoord.y)*(1-oTextureCoord.x))), vec4(0.0), vec4(1.0)); //upper left border
    FragColor = tmpColor;
} 