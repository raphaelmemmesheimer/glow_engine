#ifdef GL_ES
precision highp float;
#endif

uniform vec2 resolution;
uniform float time;

float rnd( int n )
{
    n = (n << 13) ^ n;
    n = (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff;
    return float(n);
}

float noise(int n, vec2 p)
{
  return sin(rnd(n*p.y)+rnd(n*p.x));
}

void main(void)
{
    
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    
    //uncomment for random circles
    vec2 tmp = p;
    tmp.x = p.x*p.x+p.y*p.y;
    p.y = p.x*p.x+p.y*p.y;
    p.x = tmp.x;


    vec3 color = vec3(noise(time,p),noise(1.5*time,p),noise(3*time,p));
    gl_FragColor = vec4( color,1.0);
}
