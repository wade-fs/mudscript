//__DIR__"uhen/10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	本為玉衡門副門主的辦公房. 不過後來副門主將之改建成弟子的休息室
        讓工作辛苦的門下弟子可以暫時到這間房裏來休息一下. 由此可見副門
        主對部下的關心. 進來就看到二個弟子坐在椅子上泡茶聊天. 

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"11",		//副門主室
	"southeast":__DIR__"9",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee2" : 1,		//弟子
   "open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
