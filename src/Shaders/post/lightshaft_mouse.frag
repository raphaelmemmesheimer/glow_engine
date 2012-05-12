// http://fabiensanglard.net/lightScattering/index.php
#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

in float Time;

vec4 tmpColor;
uniform sampler2D s;
uniform sampler2D s1;
uniform sampler2D s2;
uniform float brightness = 1.0;
uniform int saturation = 1;

vec4 tmpSaturation;

 uniform float exposure = 1.0;
 uniform float decay = 0.9;
 uniform float density = 0.2;
 uniform float weight = 0.2;
  vec2 lightPositionOnScreen = vec2(0.7,0.5);
 const int NUM_SAMPLES = 100 ;
 uniform vec2 mousePos;

 void main()
 {
  lightPositionOnScreen = mousePos;
  vec2 deltaTextCoord = vec2( oTextureCoord.st - lightPositionOnScreen.xy );
  vec2 textCoo = oTextureCoord.st;
  deltaTextCoord *= 1.0 / float(NUM_SAMPLES) * density;
  float illuminationDecay = 1.0;


  for(int i=0; i < NUM_SAMPLES ; i++)
   {
     textCoo -= deltaTextCoord;
     vec4 sample = texture(s, textCoo );
          sample *= illuminationDecay * weight;
          FragColor += sample;
          illuminationDecay *= decay;
  }
  FragColor *= exposure;
}


/*void main()
{   
    tmpSaturation = vec4(saturation);
    tmpColor = texture(s, oTextureCoord);
    FragColor = brightness*pow(tmpColor,tmpSaturation);
} */ 