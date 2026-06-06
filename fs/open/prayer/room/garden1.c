//open/prayer/room/garden1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花園入口");
        set("long",@LONG

	    總壇的花園，外面是一個木製的柵欄，你
	可以打開它 (open door)，走進去花園裡面瞧
	瞧，聽說裡面養有很多珍奇的野獸......不過
	你最好有心理準備!!因為怪物是不會跟你客氣
	的.

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/garden3",		//花園
        "east":"/open/prayer/room/train1-4",     //走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 0 */
  "/open/prayer/npc/dog" : 2,		//火犬
   		
]));
        create_door("north","木製柵欄", "south",DOOR_CLOSED);
  setup();
}
