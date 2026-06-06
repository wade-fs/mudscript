inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(RED"食蠱蛋"NOR,({"swallow gu egg","egg"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","
將萬種蠱蟲置放於蠱桶內，七七四十九天不放置任何食物，是其飢餓
併吞食其他的蠱類，只留下最強的蠱蟲，在使用養蠱密法使其退化成
可食用的蠱蛋，吞食此種蠱蛋，任期生長於體內，其蠱蟲成長，自然
能吞食百蠱，將體內的蠱蟲、蠱卵、蠱蛹一併吞食，清除體內蠱毒，
可謂之百蠱之王。\n");
		set("value",100000);
		set("unit","盒");
		set("base_unit","粒");
	}
	set_amount(1);
	setup();
}

void init()
{
add_action("do_eat","eat");
}

int do_eat(string arg)
{
object me,env,ob;

	me = this_player();
	env = environment(me);
	
        if( !arg )
		return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
		return 0;
        if( ob != this_object() )
		return 0;
	message_vision("$N吞食了一粒蠱蛋。\n",me);
	tell_object(me,HIR"
你感覺的到蠱蛋迅速成長，已經在你體內吞食了所有的蠱蟲、蠱卵、以及蠱蛹。\n"NOR);
	me->delete_temp("evil_no_damage");
	me->delete_temp("evil_no_enemy");
	me->clear_condition("evil_pill01");
	me->clear_condition("evil_pill02");
	me->clear_condition("evil_poison");
	add_amount(-1);
return 1;
}	
