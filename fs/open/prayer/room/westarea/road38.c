//open/prayer/room/westarea/road38.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 往東北方可以
	到達聖火教的總壇. 西方則可以到達聖火教支部的"瑤光門", 
	與飄渺四宮的"朱雀宮". 
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road37",		//街道
        "west":__DIR__"road39",		//街道
 
        ]) );
        
        set("no_fight", 0);
    setup();
}
