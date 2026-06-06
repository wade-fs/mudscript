//u/r/rence/room/tanshun/6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的西方站在一位副總教頭. 聽到總教頭在向門主
        報告督促弟子練武的情形時, 一時興奮, 也就不時地補充
        一兩句. 兩人一搭一唱, 比那說相聲的還有默契!

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
