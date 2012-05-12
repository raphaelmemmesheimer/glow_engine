#ifdef GL_ES
precision highp float;
#endif

uniform float time;
uniform vec2 resolution;
uniform vec4 mouse;

void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    vec2 m = -1.0 + 2.0 * mouse.xy / resolution.xy;

    //p.x = p.x*p.y;
    //p.y = p.y*p.y;
    vec3 color = vec3(p.x*p.x,p.y*p.y,1);
    color = reflect(sin(time),sin(abs(refract(color*time,sin(time)*color,0.5*sin(time)))));
    gl_FragColor = vec4(color,1.0);
}
