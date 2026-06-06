//open/prayer/room/westarea/road3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 往東北方可
	以到達聖火教的總壇. 西方則可以到達"白虎宮"與"天機門"
	. 白虎宮是新興起的另一個派門的分支, 可是卻很少聽說有
	人見過或碰過此一門派的門徒!!
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road1",		//街道
        "west":__DIR__"road5",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/woman2" : 1,		
        ]) );

    setup();
}
