inherit ROOM;
#include <ansi.h>
#include "damage01.c"

void create()
{
        set("short",RED"-"BLU"="HIY"幻"HIG"結"HIC"界"NOR+BLU"="RED"-"NOR);
        set("long",@LONG

七彩的通道正不斷的流動著, 你彷彿身在一個圓管內, 緩緩的前進著。

LONG);
        set("exits",([
"down":__DIR__"w14",
]));
	set("no_transmit",1);
	set_temp("evil-place",1);
        setup();
}

