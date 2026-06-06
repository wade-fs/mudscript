//u/r/rence/room/tanshun/4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的東邊有位教頭正在仔細聆聽總教頭的報告, 聽
        到不以為然處時, 則輕輕地搖頭, 不過聽到總教頭稱讚他
        的功勞時, 又深深地同意..

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
