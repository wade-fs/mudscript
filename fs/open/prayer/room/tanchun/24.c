//open/prayer/room/tanchun/24.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	天權門總管的書房, 這裡是總管處理門務的地方. 總管是門主
	以下與副門主同一職等的幹部..專門負責門內事務的處理. 東
	邊是往走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "eastsouth":__DIR__"28",	//總管房
        "east":__DIR__"23",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/paltoon1" : 1,		//保鑣
  "/open/prayer/npc/paltoon2" : 1,		//保鑣
   		
]));
     
  setup();
}
