//open/prayer/room/tangi/tangi1-40.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管房");
        set("long",
"總管的專屬辦公廳.因為總管是女性,所以整間房裡都是女性的護衛人員.南邊是總管
的書桌,東邊是往走廊.\n");

        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-41",		//總管室
	"east":"/open/prayer/room/tangi/tangi1-43",		//總管室
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon2" : 1,		//保鑣
   		
]));
     
  setup();
}
