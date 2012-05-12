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

    float eye = 1-pow(((sin(p.x*p.x*0.9))+p.y*p.y),abs(sin(time)));
    float pupil= 1-pow(p.x,2)+pow(p.y,3)+(p.x*p.x*sin(time));


    vec3 color = pupil/2+eye;
    gl_FragColor = vec4(color,1);
}
