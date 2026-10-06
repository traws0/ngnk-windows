/
 playing super mario bros theme from midi file
  midi from https://www.vgmusic.com/file/f602879e892c641b6ecbb70b1b8e05e8.html

 wav.k and midi.k come from
  https://github.com/gitonthescene/ngnk-libs/tree/master/audio

 @effbiae
\
\l wav.k
\l midi.k
FR:11025          / framerate
AMP:0.5           / amplitude
WIDTH:2           / sample width in bytes
rng:2/~!8*WIDTH   / quantization range
f:440*note[12]@   / twelve tones at concert pitch

mkpcm:{z 1:mkchnk["RIFF"]@,/("WAVE";mkfmt pcm.(x);mkchnk["data";y])}
ser:{,/+|`c$(x#256)\y}
tone:{sin[f x;AMP;0;ph[FR]y]}

d:256/256!
parse:{c:chunks@1:x
 ppqn::d@-2#c[0;1] /pulse per quarter note
 t:(itms@*|)'1_c /drop header and read tracks
 tempo::$[~^w:*&{0xff51~*x[2]}'x:,/t;d(x@w)[2;1]@!3;_5e5]
 `0:`k@`bpm,_60e6%tempo;t}

notes:{x:x@&2=*'x
 h:{(,x[1]*tempo*1e-6%ppqn),+x[2]}@+x  /deltas to times
 u:+`t`n`c`p`v!(,+\h 0),((-16 16!\:)d@'h 1),`i$(h 2 3)
 u@&|/u[`n]=/:8 9} /notes on and off (9 is note on, 8 is off)

process:{[t]
 u:{[t;x]*&(t[`t]>t[`t]x)&(t[`p]=t[`p]x)&t[`n]=8}[t]'w:&t[`n]=9 /find on/off pairs
 v:t@w;v[`u]:t[u]`t;v[`d]:v[`u]-v`t /join the pairs and find duration
 {[t;c]+c!t[c]}[v;`t`d`u`p]}   /v.t is on, v.d is duration, v.p is pitch

t:(40#process notes@)'-1_1_parse["smb.mid"] /drop the meta track and the drums

s:`f$&_FR*{x@*>x}((*|:)'t@'`u) /silence for the duration
{s::@[s;{x+!y}._FR*x`t`d;+;tone[x[`p]-57]x`d]}''t; /add in tones
mkpcm[(1;FR;WIDTH);ser[WIDTH]qnt[rng]0.5*s;wav:"smb.wav"]
$["11"~`js"11";[W:1:wav;`js"play(gg(\"W\"))"];."\\xdg-open ",wav];
