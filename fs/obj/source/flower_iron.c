// rose_flower.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR "花稜鐵" NOR,({"flower iron","tron"}));
	set("unit","塊");
	set_weight(1000);
	setup();
}
