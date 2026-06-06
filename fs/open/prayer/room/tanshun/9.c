//u/r/rence/room/tanshun/9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        在議事廳的西南角, 有一位副總管正向門主報告這一個月
        來的收支情形. 看他一臉凝重的樣子, 好像對這近的經濟
        不景氣感到很無奈..

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"6",             //議事廳
        "east":__DIR__"8",              //議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/vice-manager" : 1,            
]));

   setup();
}
