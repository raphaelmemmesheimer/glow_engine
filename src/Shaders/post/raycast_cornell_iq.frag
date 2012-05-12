// by iq --> http://www.pouet.net/topic.php?which=7920&page=21

#ifdef GL_ES
precision highp float;
#endif

uniform float time;
uniform vec2 resolution;
uniform vec4 mouse;

float planeX(in vec3 p, in float x)
{
    return distance(p,vec3(x,p.y,p.z));
}

float planeY(in vec3 p, in float y)
{
    return distance(p,vec3(p.x,y,p.z));
}

float planeZ(in vec3 p, in float z)
{
    return distance(p,vec3(p.x,p.y,z));
}

float sphere( in vec3 p, in vec3 c, in float r )
{
    return distance( p, c ) -r;
}


float f(vec3 p, out int id)
{
    float sdf;
    
    // Cornell Box (left - red, right - green, other - grey)
    float sdf1 = planeX(p,-1.0); // left wall red
    float sdf2 = planeX(p,1.0); // right wall green
    float sdf3 = planeY(p,-1.0); // floor grey
    float sdf4 = planeY(p,1.0); // ceil grey
    float sdf5 = planeZ(p,1.0); // back wall grey
    float sdf6 = sphere(p,vec3(0.4,-0.8,0.1), 0.2 );
    float sdf7 = sphere(p,vec3(0.0,-0.8,0.5), 0.2 );

                     sdf=sdf1; id=0;
    if( sdf2<sdf ) { sdf=sdf2; id=1; }
    if( sdf3<sdf ) { sdf=sdf3; id=2; }
    if( sdf4<sdf ) { sdf=sdf4; id=3; }
    if( sdf5<sdf ) { sdf=sdf5; id=4; }
    if( sdf6<sdf ) { sdf=sdf6; id=5; }
    if( sdf7<sdf ) { sdf=sdf7; id=6; }

    return sdf;
}

vec3 calcNormal( in vec3 pos )
{
    vec3 e = vec3(0.0002, 0.0, 0.0);
    vec3 n;
    int id;
    n.x = f(pos + e.xyy,id) - f(pos - e.xyy,id);
    n.y = f(pos + e.yxy,id) - f(pos - e.yxy,id);
    n.z = f(pos + e.yyx,id) - f(pos - e.yyx,id);
    return normalize(n);
}

vec3 getColor( int id )
{
    vec3 color;

         if(id==0) color = vec3(0.64,0.15,0.1);
    else if(id==1) color = vec3(0.15,0.5,0.15);
    else if(id==5) color = vec3(0.15,0.15,0.5);
    else if(id==6) color = vec3(0.5,0.15,0.5);
    else           color = vec3(0.76,0.75,0.5);
    return color;
}

void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    vec3 color = vec3(0.0,0.0,0.0);
    
    // perspective fov 45?
    vec3 Ro = vec3(0.0,0.0,-1.0); // ray origin
    vec3 Rd = vec3(p.x,p.y,1.0); // ray direction
    Rd = normalize(Rd);

    float t = 0.0;
    const int maxsteps = 75;
    for(int steps = 0; steps < maxsteps; steps++)
    {
        vec3 pos = Ro+t*Rd;
        int id;
        float d = f(pos,id);
        const float eps = 0.001;
        if(d < eps)
        {
             color = getColor( id );
             vec3 n = calcNormal( pos );
 
             // ambient occlusion
             vec4 totao = vec4(0.0);
             float sca = 1.0;
             for( int aoi=0; aoi<5; aoi++ )
             {
                 float hr = 0.01 + 0.02*float(aoi*aoi);
                 vec3 aopos = n * hr + pos;
                 int tid;
                 float dd = f( aopos, tid );
                 float ao = clamp( -(dd-hr), 0.0, 1.0);
                 totao += ao*sca*vec4(getColor(tid),1.0);
                 sca *= 0.75;
             }
             totao.w = 1.0 - clamp( 1.5*totao.w, 0.0, 1.0 );

             color  = 1.2*color*(0.6+0.4*dot(n,vec3(0.577)))*totao.w;
             color += 2.4*vec3(1.0)*pow(0.5+0.5*dot(n,Rd),2.0)*totao.w;
             color += 2.0*(0.5+0.5*color)*totao.xyz*totao.w;

             break;
        }

        t = t + d;
    }

    gl_FragColor = vec4(color,1.0);
}