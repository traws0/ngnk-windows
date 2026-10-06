/ "reticulum" on the gpu: the glsl that https://beyondloom.com/tools/specialk.html compiles it to, run through opengl32.dll
/ (reticulum.k computes the same thing in k on the cpu)  make -f win/makefile reticulum-gl
L:`"o/win/gdi.dll";win:L 2:(`win;4);poll:L 2:(`poll;1);glsl:L 2:(`glsl;1);shade:L 2:(`shade;1)

win[600;600;1;"reticulum (gpu) - esc to quit"]
glsl"precision highp float;
uniform float frame;
uniform vec2 size;
uniform vec2 mouse;
float f(vec3 x){
  x.z-=(frame*0.01);
  float a=(x.z*0.1);
  x.xy*=mat2(cos(a),sin(a),(-sin(a)),cos(a));
  return (0.1-length((cos(x.xy)+sin(x.yz))));
}
vec3 lambda_0(vec3 x){
  return (x+(f(x)*(0.5-(vec3(gl_FragCoord.xy,1.0)/size.x))));
}
void main(){
  vec3 t_0=vec3(0.0,0.0,0.0);for(int t_1=0;t_1<32;t_1++)t_0=lambda_0(t_0);
  vec3 p=t_0;
  gl_FragColor=vec4(((vec3(2.0,5.0,9.0)+sin(p))/length(p)),1.0);
}"
{*x>27=x 4}{shade 0.06*x 5}/poll 0;                          / until closed or esc. frame: 60/s of wall-clock time
