inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "小平原");
	set( "build", 24 );
        set ("long", @LONG
小小的平原，一望無際的空曠感，使你有股蕭瑟的感覺，你似乎
可以在不遠的前方看到一點人煙的氣息。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town41",
        "west"	: "/open/main/room/L21",
	]));

        setup();
}
