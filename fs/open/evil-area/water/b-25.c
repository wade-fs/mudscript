inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 揚 居 -- 後 院"NOR);
	set("long",@LONG
你站立於後院的東南角，地上已經沒有磚瓦鋪地，而是一片黃土
，這裡沒什麼特別的，在你的北邊有一座馬廄，西北方似乎有一棵大
榕樹。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-22",
"west":__DIR__"b-24",
]));
	setup();
}

 
