//open/prayer/room/tangi/tangi1-37.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","廚房");
        set("long",
"此處是明教分部之一的天機門的廚房,磚造的大灶是伙夫蒸煮的場所. \n");

        set("exits", ([ /* sizeof() == 1 */
        "west":"/open/prayer/room/tangi/tangi1-36",		//廚房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/stoker" : 1,		//伙夫
   		
]));
     
  setup();
}
