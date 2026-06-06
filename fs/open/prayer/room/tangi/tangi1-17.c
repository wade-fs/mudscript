//open/prayer/room/tangi/tangi1-17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玄關");
        set("long",
"天機門的玄關, 往裡面進去便是天機門的議事廳(open door). 外面則是天機門的練武
場,練武場上到處都是練功\強身的弟子.\n");
	set("outdoors", "/open/prayer/room"); 
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-15",		//議事廳
        "south":"/open/prayer/room/tangi/tangi1-21",		//練武場
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/duty" : 2,		//值班弟子
   		
]));
        set("light_up", 1);
create_door("north","聖火刻紋木雕門", "south",DOOR_CLOSED);
  setup();
}
