inherit ROOM;
#include <ansi.h>
#include "road.msg"
#include "damage.c"

void create ()
{
        set ("short","森林");
	set( "build", 12 );
        set ("long",(:print_road_msg:));
        set("exits",([
"east":__DIR__"forest02",
"north":__DIR__"forest04",
"west":"/open/main/room/p12",
]));
	set("no_transmit",1);
        set("light_up",-1);
setup();
}
