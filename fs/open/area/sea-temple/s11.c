inherit ROOM;
#include <ansi.h>
#include "war.c"

void create()
{
	set("short",HIB + "海神廟" + NOR);
	set("long", (:mlong():) );
	set("defence-build",10);
	set("exits",([
"south":__DIR__"s10",
"north":__DIR__"s12",
"east":__DIR__"s13",
"west":__DIR__"s08",
]));
	setup();
}
