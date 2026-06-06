#include <ansi.h>
#include <weapon.h>

inherit WHIP;
void create()
{
	set_name("繩索",({"rope"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","
一條捆綁物品所用的繩子，你也可以勉強將它視作鞭子來使用，它還有另
外一項特殊的用處---用來上吊(hang)。\n");
		set("material","iron");
		set("value",70);
		set("unit","條");
		set("wield_msg","$N將繩索抽出，握在手上當武器。\n");
		set("unwield_msg","$N將繩索放下。\n");
	}
	init_whip(5);
	setup();
}
void init()
{
	add_action("do_hang","hang");
}
int do_hang(string str)
{
	object me=this_player();
	if( !str || str!="myself")
	return notify_fail("你只能幫助自己(myself)上吊!\n");
	{
	message_vision(
"$N隨便找了一個地方，將繩子綁好，往脖子一套準備自殺，但卻不小心絆
到石頭跌了一交，跌個眼冒金星，看來$N是自殺不成啦。\n",this_player() );
	tell_object(me,"你跌了一交，受了點傷。\n");
	me->add("kee", -5);
	return 1;
	}
}

	
