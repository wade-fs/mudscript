#include <room.h>
inherit ROOM;
void create()
{
        set("short","診療室");
	set( "build", 3 );
        set("long", @LONG

    一個個清楚的穴道呈現在你眼前，有天靈穴、氣海穴、曲池穴、
玉枕穴....等，看得你眼花撩亂，你不禁開始讚嘆人體如此奧妙。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"2",             
        "south":__DIR__"8",             
        "east":__DIR__"4",              
        "west":__DIR__"6",             
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/doctor/npc/patient1" : 1,        
]));
   setup();
}


