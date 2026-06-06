inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","萬蠱洞");
	set("long",@LONG
洞內爬行著許多的蠱蟲。
LONG);
	set("evil_area",1);
	set_temp("can_hatch",1);
	set("exits",([
"east":__DIR__"gu02",
]));
	setup();
}
