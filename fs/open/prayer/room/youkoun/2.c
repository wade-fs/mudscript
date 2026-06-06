//open/prayer/room/youkoun/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","瑤光門大廳");
        set("long",@LONG

        西武林中一個勢力龐大的組織, 人們統稱她為「聖火教」
        , 又稱為明教. 此處是明教分部之一的瑤光門, 寶座上坐
        的著正是瑤光門門主. 瑤光門是聖火教排行第七的支門.

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"4",     //大廳
        "east":__DIR__"1",              //右護法
        "west":__DIR__"3",              //左護法
 
        ]) );
        set("light_up", 1);
        set("valid_startroom", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/youkoun" : 1,         //門主
]));
  setup();
}
