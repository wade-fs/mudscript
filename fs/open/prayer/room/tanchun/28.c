//open/prayer/room/tanchun/28.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	天權門總管的書房, 這裡是總管處理門務的地方. 總管是
	由門主挑選出來後, 專門負責門內事務的處理. 北邊是往
	走廊的方向.

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"24",	//總管房
        "northeast":__DIR__"22",	//總管房
        "north":__DIR__"23",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general-manager" : 1,		//總管
   		
]));
     
  setup();
}
