//open/prayer/room/tanchun/10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	天權門副門主的辦公房. 西邊是往走廊的方向, 這裡的弟子是副
	門主的隨從. 一個副門主就有如此多的隨從, 由此可見聖火教對
	於高級的幹部是有多麼的重視了. 

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"11",		//副門主室
	"southwest":__DIR__"13",		//副門主室
	"west":__DIR__"12",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
