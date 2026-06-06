inherit ROOM;
#include <ansi.h>
#include "war.c"

void create()
{
	set("short",HIB"海神廟"NOR);
	set("long", (:mlong():) );
	set("defence-build",10);
	set("exits",([
"south":__DIR__"s06",
"north":__DIR__"s08",
"east":__DIR__"s10",
"west":__DIR__"s03",
]));
	setup();
}
