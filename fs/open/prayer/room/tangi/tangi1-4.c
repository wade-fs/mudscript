//open/prayer/room/tangi/tangi1-4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天機門地牢");
        set("long",
"天機門內部的地牢(open door),往裡面再進去便是禁錮人犯的地方.\n" );

      set("item_desc", ([ /* sizeof() == 1 */
      "east" : (: look_door,     "east" :),
]));

        set("exits", ([ /* sizeof() == 2 */
        "east":"/open/prayer/room/tangi/tangi1-6",		//地牢
        "west":"/open/prayer/room/tangi/tangi1-2",		//右護法
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/jail-guard" : 1,		//地牢守衛
   		
]));
        set("no_fight", 0);
        create_door("east","地牢鐵門", "west",DOOR_CLOSED);
  setup();
}
