//open/prayer/room/tangi/tangi1-26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"練武場上的弟子一個個都在磨練自己的體能，只希望能夠早一天具備修習先天乾
坤功\的資格!!\n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-21",		//練武場
	"south":"/open/prayer/room/tangi/tangi1-31",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-27",		//練武場
        "west":"/open/prayer/room/tangi/tangi1-25",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
