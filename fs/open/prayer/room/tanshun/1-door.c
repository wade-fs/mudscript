//open/prayer/tanshun/1-door.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玄關");
        set("long",@LONG

        這裡是天璇門的玄關. 往裡面 (open door)走則是天璇門
        的議事廳. 外面則是天璇門的練武場, 練武場上到處都是
        正在鍛練身體的弟子.

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"8",             //議事廳
        "south":__DIR__"16",            //練武場
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/duty" : 2,          //值班弟子
                
]));
        set("no_fight", 0);
        set("light_up", 1);
        create_door("north","聖火刻紋木雕門", "south",DOOR_CLOSED);
  setup();
}
