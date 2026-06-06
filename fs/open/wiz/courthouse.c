// Room: /open/wiz/courthouse.c

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "法院");
	set( "build", 757 );
	set("long", @LONG
這裡是冰判官審問機器人的法院，你一定是被人檢舉或是
行為太像機器人，才會來到這裡，如果你答不出冰判官的三個
問題，可是會被冰判官踢回家睡覺唷! 好好回答(answer)吧。   
LONG
	);
	set("light_up",1);
	set("no_fight", 1);
	set("no_transmit", 1);
	set("no_chome",1);
	set("objects", ([
		__DIR__"npc/judge":1,
]));
	set("exits", ([
		"down":	STARTROOM,
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if (!present("judge", this_object()))
		return 1;
	else
		return 0;
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("忽然一陣閃光罩住了$N。\n", me);
	me->move(this_object());
}
