inherit ROOM;
#include <ansi.h>
int do_check();
int do_dest();

void create ()
{
	set("short",HIG + "琰 揚 居 -- 後 院" + NOR);
	set("long",@LONG
地上放著一塊墊高的木頭與劈材用的斧頭，如果你想劈材的話，
必須先拿起(hold)斧頭，然後再大力的砍(cut)下去。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-20",
"east":__DIR__"b-24",
]));
	setup();
}

void init()
{
add_action("do_hold","hold");
add_action("do_cut","cut");
}

int do_hold()
{
object me;

	me = this_player();

	if( me->query_temp("evil/water/cut") )
		return notify_fail("你已經高舉斧頭了。\n");

	message_vision("$N高舉著斧頭。\n",me);
	if( random(50) > (int)me->query_str() )
	{
		message_vision("$N由於力量不夠的樣子，手中的斧頭不斷的在晃動～\n",me);
		me->set_temp("evil/water/cut",1);
	}
	else
	{
		message_vision("$N拿穩了斧頭，握在手中，十分的穩健。\n",me);
		me->set_temp("evil/water/cut",2);
	}
return 1;
}

int do_cut()
{
object me,ob;
int i;

	me = this_player();

	if( !me->query_temp("evil/water/cut") )
		return 0;

	if( !present("burned-torch",environment(me)) )
	{
		me->delete_temp("evil/water/cut");
		return notify_fail("你大力揮舞著手中的斧頭，可是...地上並沒有木材可讓你砍的..\n");
	}

	message_vision("$N大力揮舞著手中的斧頭～\n",me);
	if( (int)me->query_temp("evil/water/cut") > 1 )
	{
		if( random(100) < 90 )
			me->set_temp("evil/water/cut_item",2);
		else
			me->set_temp("evil/water/cut_item",1);
	}
	else
	{
		if( random(100) < 10 )
			me->set_temp("evil/water/cut_item",2);
		else
			me->set_temp("evil/water/cut_item",1);
	}
	me->delete_temp("evil/water/cut");
	do_check();
return 1;
}

int do_check()
{
object obj,me;

	me = this_player();

	if( !me->query_temp("evil/water/cut_item") )
		return 0;
	if( (int)me->query_temp("evil/water/cut_item") > 1 )
	{
		message_vision("結果$N精準的將木材劈成兩半。\n",me);
		obj = new(__DIR__"obj/good_torch");
	}
	else
	{
		message_vision("結果$N不小心打偏了中心點，木材變的半大不小的。\n",me);
		obj = new(__DIR__"obj/bad_torch");
	}
	obj->move(environment(me));
	me->delete_temp("evil/water/cut_item");
	do_dest();
return 1;
}

int do_dest()
{
object me,obj;

	me = this_player();
	obj = present("burned-torch",environment(me));

	if( present("burned-torch",environment(me)) )
		destruct(obj);
return 1;
}
