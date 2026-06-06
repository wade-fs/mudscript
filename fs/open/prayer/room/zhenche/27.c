//u/r/rence/room/zhenche/27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西南角, 有兩個弟子正在交換練武的心得. 一
        講到聖火武學, 彼此眼中都散發出異樣眼光, 好像都忘了
        練武的辛苦. 難道聖火的上乘武功真的這麼吸引人嗎?

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
