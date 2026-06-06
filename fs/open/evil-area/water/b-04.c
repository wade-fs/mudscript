inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 揚 居"NOR);
	set("long",@LONG
走道上，陽光透過窗戶，照進了琰揚居內，你正行走於廚房與大
廳間的通道，窗戶在走道的北邊，而南邊是緊閉的門檻，在門檻內，
你猜測那大概是客房吧...儘管偶爾會傳來陣陣淒涼的哭聲...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-03",
"east":__DIR__"b-05",
]));
	setup();
}

 
