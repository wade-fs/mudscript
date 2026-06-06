inherit ROOM;
#include <ansi.h>
#include "road.msg"
#include "damage.c"

void create ()
{
        set ("short","森林");
        set ("long",(:print_road_msg:));
        set("exits",([			//設定出口
"north":__DIR__"forest16",
]));
        set("objects",([		//設定物件
__DIR__"npc/thief01":1,
__DIR__"npc/robber01":1,
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
