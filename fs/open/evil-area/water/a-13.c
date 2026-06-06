inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 揚 湖"NOR);
	set("long",@LONG
往湖泊的中心望去，你似乎看到有一座建築物正漂浮於湖面上，
儘管你十分的想涉水而過，不過你的理智阻止了你這麼做，對於從未
知曉的湖泊，你連裡面有活動著什麼生物都不曉得，還是小心點好。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-14",
"north":__DIR__"a-12",
]));
	setup();
}

 
