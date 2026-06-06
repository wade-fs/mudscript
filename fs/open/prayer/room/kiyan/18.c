//open/prayer/room/kiyan/18.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	開陽門總管的書房, 這裡是總管處理門務的地方. 總管是門主以下
	與副門主同一職等的幹部..專門負責門內事務的處理. 北邊是往走
	廊的方向. 西北邊是總管的所在地. 

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "northwest":__DIR__"19",		//總管房
        "north":__DIR__"17",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon1" : 1,		//保鑣
   		
]));
     
  setup();
}
