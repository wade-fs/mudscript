// rose_flower.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY + "璃金石" + NOR,({"gold stone","stone"}));
	set("unit","顆");
	set_weight(1000);
	setup();
}
