//u/r/rence/room/zhenche/4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的東邊有位教頭正在仔細聆聽門主的吩咐. 看他
        汗顏的樣子, 顯然門主並不滿意最近門生練武的情形. 尤
        其三年一度的比武大會又快到了, 難怪門主會不高興.

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"7",             //議事廳
        "north":__DIR__"1",             //議事廳
        "west":__DIR__"5",              //議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general" : 1,         //教頭
]));

   setup();
}
