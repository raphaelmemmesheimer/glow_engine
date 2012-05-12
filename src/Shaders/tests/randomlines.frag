#ifdef GL_ES
precision highp float;
#endif

uniform vec2 resolution;
uniform float time;

float coolfFunc3d2( int n )
{
    n = (n << 13) ^ n;
    n = (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff;
    return float(n);
}

void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    vec3 color = vec3(sin(coolfFunc3d2(gl_FragCoord.xy)),sin(coolfFunc3d2(gl_FragCoord.xy)),sin(coolfFunc3d2(1)));
    gl_FragColor = vec4( color*sin(time),1.0);
}
