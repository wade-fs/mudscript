inherit ROOM;
#include <ansi.h>
#include "road.msg"
#include "damage.c"
string look_button();

void create ()
{
        set ("short","森林");
        set ("long",(:print_road_msg:));
        set("exits",([			//設定出口
"east":__DIR__"forest24",
]));
        set("item_desc",([		//設定路標
"按鈕":(:look_button:),
]));
        set("objects",([		//設定物件
__DIR__"npc/thief02":1,
__DIR__"npc/robber02":1,
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}

string look_button()
{
	message_vision(HIY + "\n$N走向某一棵樹木。
突然腳底踩空，$N滑入樹底隧道！\n\n" + NOR,this_player());
	this_player()->move(__DIR__"fortress01");
	return "";
}
