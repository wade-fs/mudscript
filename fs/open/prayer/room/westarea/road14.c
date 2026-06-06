//open/prayer/room/westarea/road14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 往東北方可
	以到達聖火教的總壇. 西方則可以到達"天璇門"與"天機門"
	. 西域聖火教的位置剛好是在一個盆地之間, 地勢由東向西
	下降, 南邊則是盆地的開口!
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road13",		//街道
        "west":__DIR__"road15",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/man1" : 1,		
        ]) );

    setup();
}
