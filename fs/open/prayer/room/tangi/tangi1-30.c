//open/prayer/room/tangi/tangi1-30.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"天機門的練武場,場上到處可見練功\的門生. 東邊是大門,北邊則可以通往議事廳\n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-25",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-31",		//練武場
       
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 3,		//弟子
   		
]));
     
  setup();
}
