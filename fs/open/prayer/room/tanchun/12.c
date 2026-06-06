//open/prayer/room/tanchun/12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	天權門副門主的辦公房. 西邊是往走廊的方向, 南邊是往副門主
	的書房. 看這兩位站崗的弟子有說有笑的, 相信聖火教一定是一
	個很不錯的組織了.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"11",		//副門主室
	"south":__DIR__"13",		//副門主室
	"west":__DIR__"14",		//走廊
        "east":__DIR__"10",		//副門主室
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee1" : 1,		//弟子
   "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
