inherit ROOM;
#include <ansi.h>
#include "road.msg"
#include "damage.c"

void create ()
{
        set ("short","森林");
        set ("long",(:print_road_msg:));
        set("exits",([			//設定出口
"west":__DIR__"forest14",
"east":__DIR__"forest16",
]));
	set("no_transmit",1);
        set("light_up",-1);		//有光線
setup();
}
