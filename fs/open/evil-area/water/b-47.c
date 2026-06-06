inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIG"琰 揚 居 -- 後 院"NOR);
	set("long",@LONG
屋內的裝潢十分的樸素，除了一張大黃石桌與一些木椅以外，就
沒有其他的擺設了。
LONG);
        set("evil_area",1);
        set("no_transmit",1);
	set("exits",([
"out":__DIR__"b-26",
]));
	setup();
}
