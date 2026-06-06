//open/prayer/room/kiyan/9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	開陽門副門主的辦公房，西邊是往走廊的方向，西南邊
	是副門主的書房. 

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northwest":__DIR__"10",		//副門主室
	"southwest":__DIR__"12",		//副門主室
	"west":__DIR__"11",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
