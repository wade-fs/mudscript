inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 揚 居 -- 後 院"NOR);
	set("long",@LONG
你站立於後院的西北角，地上已經沒有磚瓦鋪地，而是一片黃土
，這裡沒什麼特別的，在你的南邊有一棵大樹，東南方似乎有一座馬
廄。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"b-20",
"east":__DIR__"b-18",
]));
	setup();
}

 
