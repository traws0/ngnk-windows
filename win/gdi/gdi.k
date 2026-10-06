/ graphics through the ffi (win/gdi/gdi.c). from the repo root: make -f win/makefile gdi
/ win[w;h;scale;title] opens a window, draw paints a w*h list of 0xrrggbb ints (stretched to the window),
/ draw and poll 0 handle events and give (open;mouse x;mouse y;mouse buttons;key;ms since win)
L:`"o/win/gdi.dll";win:L 2:(`win;4);draw:L 2:(`draw;1);poll:L 2:(`poll;1)

w:320;h:240;i:!w*h;X:w!i;Y:_i%w
fr:{[t;e]c:(65536*256!X+t)+(256*256!Y+2*t)+64+191*0<e 3      / moving gradient, blue while a button is down
 d:((X-e 1)*X-e 1)+(Y-e 2)*Y-e 2;c|16777215*d<400}             / white disc at the mouse
{*x>27=x 4}{draw fr[_0.06*x 5;x]}/win[w;h;2;"k gdi - esc to quit"]; / until closed or esc
