#ifdef GL_ES
precision highp float;
#endif

uniform vec2 resolution;
uniform float time;

float PI = 3.14159;


//calc polar theta from cartesian xy
float theta(float x, float y)
{
  float result = 0.0;
  if (x > 0.0)
    result = atan(y/x);
  if (x < 0.0 && y >= 0.0)
    result = atan(y/x)+PI;
  if (x < 0.0 && y < 0.0)
    result = atan(y/x)-PI;
  if (x == 0.0 && y > 0.0)
    result = PI/2;
  if (x == 0.0 && y < 0.0)
    result = -PI/2.0;
  if (x == 0.0 && y == 0.0)
    result = 0.0;
  return result;
}

//calc polar r from cartesian 
float calcr(float x, float y) 
{
  return sqrt(x*x+y*y);
}

// superformula 
float superformula(float a, float b, float m, float theta, float n1, float n2, float n3)
{
  float mt =m*theta;
  return (pow(pow(abs(cos(mt/4.0)/a),n2) + pow(abs(sin(mt/4.0)/a),n3),1.0/n1));
}


void main(void)
{
    vec2 p = -1.0 + 2.0 * gl_FragCoord.xy / resolution.xy;
    vec2 s = p;
    if (time < 10)
    {
      p = p.xy*tan(p.xy*tan(time));
    }
    else
      p = p.xy*sin(p.xy*2);
    float color = superformula(sin(time),1.0,8,theta(p.x,p.y),sin(time),sin(time),8)*calcr(p.x,p.y);
    gl_FragColor = vec4(color,color*color,color,1.0);
}
