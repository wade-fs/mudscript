// waterskin.c
#include <ansi.h>
inherit ITEM;
#include "/feature/liquid.c"

void create()
{
	set_name( HIR"<滿>"HIC"十錦琺瑯杯" NOR, ({"full-wine","wine"}));
	set_weight(50);
	set("unit", "個");
	set("value", 2000);
	set("飽和", 3);
	set("液體", ([
		"種類": "酒",
		"名稱": "冰清冽酒",
		"剩": 3,
		"drunk_apply": 6,
	]) );
	setup();
}
