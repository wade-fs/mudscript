//open/prayer/room/uhen/9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	玉衡門副門主的辦公房.桌上擺滿了一些文件.你看到一個弟子
        正在整理文件. 大概是整理完後要交給副門主過目的吧.

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
