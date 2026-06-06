// waterskin.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC + "十錦琺瑯杯" + NOR, ({"ten-cup","cup"}));
	set_weight(50);
	set("unit", "個");
	set("value", 2000);
	setup();
}
