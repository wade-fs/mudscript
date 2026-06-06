//open/prayer/room/tanchun/1-door.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玄關");
        set("long",@LONG

	天權門的玄關, 往裡面進去便是天權門的議事廳(open door). 
	外面則是天權門的練武場, 練武場上到處都是練功強身的弟子 
	. 只要能夠在三年舉辦一次的比武大會上脫穎而出, 就能在教
	內獲得一席之地!!

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"8",		//議事廳
        "south":__DIR__"16",		//練武場
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/duty" : 2,		//值班弟子
   		
]));
        set("no_fight", 0);
        set("light_up", 1);
        create_door("north","聖火刻紋木雕門", "south",DOOR_CLOSED);
  setup();
}
