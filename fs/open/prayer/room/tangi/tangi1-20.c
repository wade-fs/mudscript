//open/prayer/room/tangi/tangi1-20.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",
"天機門的走廊，走廊上可見到跑門正在辛勞的四處奔波，走廊的廊頂是使用上等的
西域檜木建造的，隨時都會散發出特有的檜木香．副總教頭正在督促著門人練武.\n");

        set("outdoors", "/u/r/rence");
        set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
        "south":"/open/prayer/room/tangi/tangi1-25",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-21",		//走廊
        "west":"/open/prayer/room/tangi/tangi1-19",		//走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		//副總教頭
   		
]));
                
  setup();
}
