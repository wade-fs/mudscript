inherit ROOM;
#include <ansi.h>
#include "damage01.c"

void create()
{
        set("short",RED + "-" + BLU + "=" + HIY + "幻" + HIG + "結" + HIC + "界" + NOR+BLU + "=" + RED + "-" + NOR);
        set("long",@LONG

七彩的通道正不斷的流動著, 你彷彿身在一個圓管內, 緩緩的前進著。

LONG);
        set("exits",([
"west":__DIR__"w20",
"east":__DIR__"w15",
"south":__DIR__"w16",
"north":__DIR__"w17",
]));
	set("no_transmit",1);
	set_temp("evil-place",1);
        setup();
}

