// rose_flower.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG + "青龍石" + NOR,({"green stone","stone"}));
	set("unit","顆");
	set_weight(1000);
	setup();
}
