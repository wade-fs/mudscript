//u/r/rence/room/tanshun/3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天璇門大廳");
        set("long",@LONG

        這裡站著一位左護法, 與右護法專職保護門主的重要工作
        . 其後是一座繡工精美的屏風, 正對著大廳右方的大幅潑
        墨畫, 兩者相互輝映!

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"2",              //門主
        "south":__DIR__"6",                 
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/left" : 1,            //左護法
]));
  setup();
}

