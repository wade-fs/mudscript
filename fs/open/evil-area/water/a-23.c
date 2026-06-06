inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + HIG + " 同 心 橋 " + NOR);
	set("long",@LONG
你走在石製的橋上，腳底下踩著厚實的石塊卻還是有晃動的感覺
，你心想，難不成橋快要垮了不成？想了想，你開始加緊腳步離去～
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-01",
"east":__DIR__"a-24",
]));
	setup();
}

 
