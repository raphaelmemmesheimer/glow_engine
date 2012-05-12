#ifdef GL_ES
precision highp float;
#endif

uniform vec2 resolution;
uniform float time;
uniform sampler2D tex0;
uniform sampler2D tex1;

void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    p.x *= resolution.x/resolution.y;
    float color = p.x*p.x*cos(time)+p.y*p.y*sin(time);
    gl_FragColor = vec4(color*color,cos(time),color*sin(time),1);
}
