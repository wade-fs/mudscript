//open/prayer/room/westarea/road20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 往東可以到
	達聖火教支門的"天權門"與"開陽門". 北邊是錢莊. 破邪洞
	窟的出入口除了山壁外, 聽說在總壇內也有另一個出入口!!
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
       "north":__DIR__"r1-16.c",	//錢莊  
       "east":__DIR__"road19",		//街道
       "west":__DIR__"road21",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
