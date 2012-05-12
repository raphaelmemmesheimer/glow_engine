#version 330 
// @ param blurWidth float - distance between texture samples

in vec2 oTextureCoord;
uniform sampler2D tex00;
out vec4 FragColor;

uniform float blurWidth = 0.0;

void main(void) 
{ 
  FragColor = texture(tex00,oTextureCoord); // center
  if (blurWidth != 0.0) { // cancel if theres no blur ... texture lookups are expensive
    FragColor += texture(tex00,oTextureCoord+blurWidth);
    FragColor += texture(tex00,oTextureCoord-blurWidth);
    FragColor += texture(tex00,vec2(oTextureCoord.x-blurWidth,oTextureCoord.y));
    FragColor += texture(tex00,vec2(oTextureCoord.x+blurWidth,oTextureCoord.y));
    FragColor += texture(tex00,vec2(oTextureCoord.x,oTextureCoord.y+blurWidth));
    FragColor += texture(tex00,vec2(oTextureCoord.x,oTextureCoord.y-blurWidth));
    FragColor/=7;
  };
} 