#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
一堆已經腐化的屍體氣味夾雜著食物的腐敗臭味直衝你鼻口，令你不由得喉嚨
一陣酸澀，你掩住鼻子望了下四周，看來食物都早已經腐爛消失了，所剩的都只有
屍骨與一些烹飪器材，也許這裡曾經是一些廚師大顯身手的地方。
LONG);
set("exits",([
"east":__DIR__"b_r06",
]));
setup();
}
