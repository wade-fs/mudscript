//open/prayer/room/tanchun/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	天權門總管的書房, 這裡是總管處理門務的地方. 總管是門主以
	下與副門主同一職等的幹部..專門負責門內事務的處理. 西邊是
	往走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"28",	//總管房
        "west":__DIR__"23",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon1" : 1,		//保鑣
   		
]));
     
  setup();
}
