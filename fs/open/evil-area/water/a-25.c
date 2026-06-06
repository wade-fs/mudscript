inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + HIG + " 同 心 橋 " + NOR);
	set("long",@LONG
在你的正南方，也就是同心橋的終點，有著一個類似人間的建築
物，看起來雖然有點簡陋，卻不失風雅，感覺上裡面似乎居住著一位
隱士，不過卻又不像是隱士所會做的行為，因為門前站立著兩個邪靈
，似乎不是普通人可以任意通行。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"a-24",
"south":__DIR__"a-26",
]));
	setup();
}

 
