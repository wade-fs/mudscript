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
"west":__DIR__"forest06",
]));
        set("objects",([		//設定物件
__DIR__"npc/thief01":1,
__DIR__"npc/robber01":1,
]));
        set("item_desc",([		//設定路標
"按鈕":(:look_button:),
]));
	set("no_transmit",1);
        set("light_up",-1);		//有光線
setup();
}

void init()				//出現提示
{
	if(random(100)<50 && !this_object()->query_temp("msg01"))
	{
		call_out("msg01",1,this_player());
		this_object()->set_temp("msg01",1);
	}
}

int msg01(object me)
{
	tell_object(me,HIY + "\n你突然發現附近其中一棵樹的樹幹上有著一個奇怪的按鈕！\n\n" + NOR);
	this_object()->delete_temp("msg01");
	return 1;
}

string look_button()
{
	message_vision(HIY + "\n$N走向某一棵樹木。
突然腳底踩空，$N滑入樹底隧道！\n\n" + NOR,this_player());
	this_player()->move(__DIR__"forest14");
	return "";
}
