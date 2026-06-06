//open/prayer/room/tangi/tangi1-9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天機門地牢");
        set("long",@LONG
此處是明教分部之一的天機門內部的地牢. 
LONG);
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/tangi/tangi1-8",		//石牢房
        "south":"/open/prayer/room/tangi/tangi1-10",		//石牢房
        "west":"/open/prayer/room/tangi/tangi1-6",		//地牢
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/picket" : 1,		//監獄巡察
]));
	
  setup();
}
