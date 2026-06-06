//u/r/rence/room/zhenche/7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的東南角, 有一個總教頭正一臉無奈的樣子. 想
        必也對督導門生練武不週的事感到很愧咎! 氣氛也顯得很
        凝重!

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"4",             //議事廳
        "west":__DIR__"8",              //議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-officer" : 1,         
]));

   setup();
}
