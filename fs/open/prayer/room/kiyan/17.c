//open/prayer/room/kiyan/17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	開陽門總管的書房, 這裡是總管處理門務的地方. 總管是門主以下
	與副門主同一職等的幹部..所以你可以發現房內有許多的保鑣在護
	衛著總管大人. 北邊是往走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"16",		//總管房
        "south":__DIR__"18",		//總管房
        "east":__DIR__"15",		//總管房
        "west":__DIR__"19",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon2" : 2,		//保鑣
   		
]));
     
  setup();
}
