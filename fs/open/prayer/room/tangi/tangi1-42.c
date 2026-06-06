//open/prayer/room/tangi/tangi1-42.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管房");
        set("long",
"總管的專屬辦公廳.因為總管是女性,所以整間房裡都是女性的護衛人員.西邊是總管
的書桌,東邊是往走廊.\n");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-41",		//總管室
	"east":"/open/prayer/room/tangi/tangi1-45",		//總管室
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon1" : 1,		//保鑣
   		
]));
     
  setup();
}
