//u/r/rence/room/zhenche/6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的西方站在一位副總教頭. 聽到門主對門生的練
        武不滿意時, 一時氣餒無話可說, 只有默默低頭接受門主
        的責備.

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"3",             //議事廳
        "south":__DIR__"9",             //議事廳
        "east":__DIR__"5",              //議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/major-officer" : 1,           
]));

   setup();
}
