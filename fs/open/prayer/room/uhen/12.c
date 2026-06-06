//__DIR__"12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	玉衡門副門主的辦公房.一進來你就看到副門主跟身旁的弟子
        在討論玉衡門的門下事務.似乎相當的忙錄. 看來要當一個副
        門主也是要有相當的才能方可.  

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"11",		//副門主室
	"northeast":__DIR__"9",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/vice-chair" : 1,		
        "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
