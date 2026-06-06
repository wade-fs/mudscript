inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
你可以看到湖泊旁，佇立著幾隻人間界的鱞鳥，一種會捕魚的鳥
，真沒想到竟然在此地也可以看到如此的生物，你不禁感慨著這裡的
生活，真是一個安詳的地方啊～
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-09",
"west":__DIR__"a-07",
]));
	setup();
}

 
