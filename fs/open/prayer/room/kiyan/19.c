//open/prayer/room/kiyan/19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	開陽門總管的書房, 這裡是總管處理門務的地方. 總管是門主以下
	與副門主同一職等的幹部..專門負責門內事務的處理. 東邊是往走
	廊的方向. 總管正在抄寫門主所批發下來的卷宗!!

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northeast":__DIR__"16",	//總管房
        "southeast":__DIR__"18",	//總管房
        "east":__DIR__"17",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general-manager" : 1,		//總管
   		
]));
     
  setup();
}
