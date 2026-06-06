//open/prayer/room/tangi/tangi1-48.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",
"天機門副門主的辦公房.北邊是往走廊的方向,東邊是往副門主的書房. \n");

        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-47",		//副門主室
	"east":"/open/prayer/room/tangi/tangi1-51",		//副門主室
       
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
   		
]));
     
  setup();
}
