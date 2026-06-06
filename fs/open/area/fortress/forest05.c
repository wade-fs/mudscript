inherit ROOM;
#include <ansi.h>
#include "road.msg"
#include "damage.c"

void create ()
{
        set ("short","森林");
        set ("long",(:print_road_msg:));
        set("exits",([			//設定出口
"west":__DIR__"forest04",
"east":__DIR__"forest06",
"south":__DIR__"forest02",
]));
	set("no_transmit",1);
        set("light_up",-1);		//有光線
setup();
}
