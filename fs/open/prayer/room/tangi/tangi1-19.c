//open/prayer/room/tangi/tangi1-19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",
"天機門的走廊，走廊上可見到跑門正在辛勞的四處奔波，走廊的廊頂是使用上等的
西域檜木建造的，隨時都會散發出特有的檜木香．\n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-24",		//走廊
	"east":"/open/prayer/room/tangi/tangi1-20",		//走廊
       
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/footman" : 1,		//跑堂
   		
]));
     
  setup();
}
