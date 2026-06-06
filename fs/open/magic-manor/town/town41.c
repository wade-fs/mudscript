inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "平原小徑");
	set( "build", 7 );
        set ("long", @LONG
走了許久，總算走到一條較像樣的路了，前方不遠處似乎是有人
煙的樣子，可以看見幾間零星的房子座落在前方。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town38",
        "west"	: __DIR__"town40",
	]));

        setup();
}
