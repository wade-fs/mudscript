//u/r/rence/room/tanshun/27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西南角, 有兩個弟子正在交換練武的心得. 看
        他們講得津津有味的樣子, 好像已經忘了練武的艱苦. 難
        道聖火的上乘武功真的這麼吸引人嗎?

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"21",            
        "east":__DIR__"26",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee3" : 1,                //弟子
                
]));
     
  setup();
}
