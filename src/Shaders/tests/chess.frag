
uniform float time;
uniform vec2 resolution;
uniform vec4 mouse;

out vec4 fragColor;
in vec3 Pos;

void main(void)
{
//    vec2 p = (2.0*Pos.x-resolution)/resolution.y;

    vec4 red =  vec4(1.0,1.0,0.0,1.0);
    vec4 blue =  vec4(0.0,1.0,0.0,1.0);
    vec4 green =  vec4(0.0,0.0,1.0,1.0);

    vec4 color;

    float m = min(sin(time/20),0.5);
    if (min(sin(Pos*m),sin(Pos*m)) == sin(Pos*m))
    {
      color = vec4(sin(time*0.1),sin(time*0.1),sin(time*0.1),1.0);
    }
     else 
    {
     color = vec4(0.0,0.0,1.0,0.5);
    };
    
    fragColor =color;
}
