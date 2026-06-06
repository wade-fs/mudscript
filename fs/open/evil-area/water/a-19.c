inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
鳥啼清脆且響亮，陣陣暖風吹拂，感覺好不痛快～
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"a-20",
"east":__DIR__"a-18",
]));
	setup();
}

 
