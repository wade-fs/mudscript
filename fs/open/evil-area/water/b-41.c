inherit ROOM;
#include <ansi.h>
#include "tree.msg"

void create()
{
	set("short",HIG"琰 揚 居 -- "NOR+YEL"大 松 樹"NOR);
	set("long",@LONG
你突然被這裡的某樣東西所吸引，不是美麗的風景，也不是奇特
的邪靈，而是一種會散發出奇特味道的樹脂，一隻闕雀正在一旁拉扯
著那快要斷裂的樹枝，拉著拉著，一股奇特的味道讓闕雀忍不住放棄
了這根樹枝飛離開了這棵大松樹，看來你只要在出點力氣就可以將木
枝給拔(uproot)了下來。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-40",
]));
	setup();
}

void init()
{
add_action("do_uproot","uproot");
}

int do_uproot()
{
object me,obj;
int str;

	me = this_player();
	str = (int)me->query_str();

	if( me->query_temp("evil/water/uproot") )
		return notify_fail("樹枝已經被拔走了，只留下一個斷裂的樹幹。\n");
	message_vision("$N一使力，整個樹枝都被拔了下來。\n",me);
	obj = new(__DIR__"obj/keep_bee");
	obj->move(me);
	tell_object(me,"你拿到了一個"+obj->name(1)+"。\n");
	me->set_temp("evil/water/uproot",1);
	if( str > random(50) )
	{
		message_vision("$N拔的太大力，結果一不小心就掉了下去...\n",me);
		tell_object(me,HIY"你心想：完了...:~...\n"NOR);
		me->move("/open/evil-area/water/b-20");
		me->receive_wound("gin",200);
		me->receive_wound("kee",300);
		me->receive_wound("sen",100);
		COMBAT_D->report_status(me,1);
		return 1;
	}
return 1;
}

