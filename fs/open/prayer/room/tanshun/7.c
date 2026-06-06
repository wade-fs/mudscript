//u/r/rence/room/tanshun/7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的東南角, 有一個總教頭正在報告門中弟子簹Z
        的情形. 說到得意處, 不禁露出得意的笑容! 似乎對這次
        三年一度的比武大會抱著極大的信心!

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
