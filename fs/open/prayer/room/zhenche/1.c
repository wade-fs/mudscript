//open/prayer /zhenche/1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","陣勢門大廳");
        set("long",@LONG

        陣勢門大廳裝潢給人一種豪邁爽朗的感覺. 兩旁的客椅一
        字排開, 直到廳尾. 用的都是西域的上等木材所製! 大廳
        右邊站著一位右護法.

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"4",             //大廳
        "west":__DIR__"2",              //門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/right" : 1,           //右護法
]));
  setup();
}

