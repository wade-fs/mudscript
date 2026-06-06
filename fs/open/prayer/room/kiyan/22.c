//open/prayer/room/kiyan/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	開陽門的練武場, 練武場上的弟子正在修練內功\. 只見每位弟
	子盤坐在地, 個個面額汗水斗大如珠, 汗流浹背, 不過體格上
	卻也比一般弟子來的強健多了.

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"15",		
        "east":__DIR__"21",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
