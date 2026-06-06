//open/prayer/room/youkoun/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

        一進入總管的書房, 就有一個保鑣猛盯著你瞧! 似乎在防
        犯你鬧事. 看看四週, 其實也沒有什麼好值得你鬧事的,
        真是窮緊張!

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"12",            //總管房
        "south":__DIR__"14",            //總管房
        "east":__DIR__"11",             //總管房
        "west":__DIR__"15",             //總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/paltoon2" : 1,                //保鑣
                
]));
     
  setup();
}
