//u/r/rence/room/zhenche/3.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","陣勢門大廳");
        set("long",@LONG

        這裡站著一位左護法, 與右護法專職保護門主的重要工作
        . 看他雄糾糾氣昂昂的樣子, 就知道是訓練有素的護法! 
        從你一踏入大廳開始, 他就已經在注意你的一舉一動了!

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

