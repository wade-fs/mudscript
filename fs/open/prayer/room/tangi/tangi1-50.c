//open/prayer/room/tangi/tangi1-50.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",
"天機門副門主的辦公房.西邊是往走廊的方向,東邊是往副門主的書房.\n" );

        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-49",		//副門主室
	"south":"/open/prayer/room/tangi/tangi1-51",		//副門主室
	"west":"/open/prayer/room/tangi/tangi1-47",		//副門主室
        "east":"/open/prayer/room/tangi/tangi1-52",		//副門主書房
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
   		
]));
     
  setup();
}
