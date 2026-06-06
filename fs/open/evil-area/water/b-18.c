inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG + "琰 揚 居 -- 後 院" + NOR);
	set("long",@LONG
你正在站一個磚塊作成的小階梯上，往南望去，有一間木製的房
屋，那裡應該就是後廂房了，在通往房屋的途中，有一塊空地，空地
上有著馬廄與一棵大榕樹，往北則是回到大廳。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-17",
"south":__DIR__"b-21",
"east":__DIR__"b-27",
"west":__DIR__"b-19",
]));
	setup();
}

 
