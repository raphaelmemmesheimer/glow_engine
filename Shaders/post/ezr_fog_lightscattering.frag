// http://fabiensanglard.net/lightScattering/index.php
#version 330
in vec3 EyespaceNormal;
in vec2 oTextureCoord;
in vec3 Pos;

out vec4 FragColor;

uniform float Time;

uniform sampler2D s;
uniform sampler2D s1;
uniform sampler2D s2;
uniform sampler2D sScene;
uniform sampler2D sNormal;
uniform sampler2D sDepth;

uniform vec2 mousePos;
uniform vec2 resolution;

uniform float exposure = 0.0034;
uniform float decay = 1.0;
uniform float density = 1.0;
uniform float weight = 5.0;
uniform vec2 lightPositionOnScreen = vec2(0.7,0.5);
uniform vec4 fogColor = vec4(0.0,0.0,0.6,1.0);

int NUM_SAMPLES = 100;

//calculate depthfog 
vec4 applyFog(vec4 inColor){
  vec4 depthColor = texture(sDepth,oTextureCoord);
  vec4 fogDistance = vec4(100.0);//vec4((sin(Time*0.25)+1)*100);
  vec4 fogFactor = pow(depthColor,fogDistance);
  if (depthColor == vec4(1.0))
    fogFactor = vec4(0.0);
  
  return mix(inColor,fogColor , fogFactor);
}

//calculate Light Scattering
vec4 applyLightScattering(vec4 inColor){
  vec4 lightScatteringColor = texture(s, oTextureCoord);
  vec2 deltaTextCoord = vec2( oTextureCoord - lightPositionOnScreen);
  vec2 textCoord = oTextureCoord;
  deltaTextCoord *= 1.0 / float(NUM_SAMPLES) * density;
  float illuminationDecay = 1.0;

  for(int i=0; i < NUM_SAMPLES ; i++)
   {
          textCoord -= deltaTextCoord;
          vec4 sample = texture(s, textCoord);
          sample *= illuminationDecay * weight;
          lightScatteringColor += sample;
          illuminationDecay *= decay;
  }
  lightScatteringColor *= exposure;
  return inColor + lightScatteringColor;
}

void main()
 {
  FragColor = texture(sScene,oTextureCoord);
  FragColor = applyLightScattering(FragColor);
  FragColor = applyFog(FragColor); //texture(s,oTextureCoord)
}  