//open/prayer/room/westarea/road9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華, 西邊是西域著名
	的市集, 你可以在那裡買賣物品!!或許你可以在那裡買到特殊的
	武器喔!!不過那可要看你的運氣如何了........
    東邊, 就是西域的驛站了
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road1",		//街道
	"south":__DIR__"road13",	//街道
	"west":__DIR__"sushop",		//商店
    "east" : "/open/trans/room/room6", //驛站
 
        ]) );
        setup();
}
