#ifdef GL_ES
precision highp float;
#endif

uniform float time;
uniform vec2 resolution;
uniform vec4 mouse;
uniform sampler2D tex0;
uniform sampler2D tex1;

void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    vec2 m = -1.0 + 2.0 * mouse.xy / resolution.xy;

    vec3 color = vec3(p.x*p.x,p.y*p.y,1);
    gl_FragColor = vec4(sin(color*time),1.0);
}
