//open/prayer/room/tangi/tangi1-46.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",
"天機門副門主的辦公房.南邊是往走廊的方向,東邊是往副門主的書房. \n");

        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-47",		//副堂主室
	"east":"/open/prayer/room/tangi/tangi1-49",		//副堂主室
       
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/puncher" : 1,		//拳師
   		
]));
     
  setup();
}
