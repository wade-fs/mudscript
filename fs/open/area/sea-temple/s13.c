inherit ROOM;
#include <ansi.h>
#include "war.c"

void create()
{
	set("short",HIB + "海神廟" + NOR);
	set("long", (:mlong():) );
	set("defence-build",10);
	set("exits",([
"north":__DIR__"s14",
"west":__DIR__"s11",
]));
	setup();
}
