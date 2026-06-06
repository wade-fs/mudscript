inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 揚 居 -- 後 院"NOR);
	set("long",@LONG
在你眼前，有一座木製的馬廄，馬廄內只養育一匹金黃色的駿馬
，全身泛著金黃色的光芒，十分的炯炯有神，彷彿天將神兵一般的氣
勢讓你不敢隨意動牠分毫。
LONG);
	set("no_fight",1);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-27",
"south":__DIR__"b-25",
"west":__DIR__"b-21",
]));
	set("objects",([
__DIR__"npc/horse":1,
]));
	setup();
}

 
