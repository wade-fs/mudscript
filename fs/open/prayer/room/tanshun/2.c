//open/prayer/room/tanshun/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天璇門大廳");
        set("long",@LONG

        西武林中一個勢力龐大的組織, 人們統稱她為「聖火教」
        , 又稱為明教. 此處是明教分部之一的天璇門, 寶座上坐
        著的正是天璇門的門主, 兩旁則分別有左右護法. 天璇門
        是聖火教排行第四的支門.

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"5",             //大廳
        "east":__DIR__"1",              //右護法
        "west":__DIR__"3",              //左護法
 
        ]) );
        set("light_up", 1);
        set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/tanshun" : 1,               //門主
]));
  setup();
}
