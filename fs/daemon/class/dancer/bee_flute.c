inherit COMBINED_ITEM;
#include <ansi.h>
void create ()
{
        set_name(HIY" 蜂 笛 "NOR,({"bee flute","flute"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
                set("unit", "堆");
                set("base_unit", "枝");
                set("value","10");
		set("long","一隻由蜂蜜所製成銅黃色的笛子, 可以召喚蜜蜂出來攻擊敵人。

使用方法 : attack <目標>\n");
        }
set_amount(1);
setup();
}

void init()
{
add_action("do_attack","attack");
}

int do_attack(string arg)
{
object me,ob,env,target;
string d_msg;
int i,sk,t_sk,limit;

	me = this_player();
	ob = this_object();
	env = environment(me);
	sk = me->query_skill("order-bee",1);

	if( !arg )
		return 0;
 	if( !present("bee flute",me) )
		return notify_fail("蜂笛需要攜帶於身上才能使用。\n");

	if( !present(arg,env) )
		return notify_fail("蜂笛使用方法 : attack <目標> \n");

	target = present(arg,env);

	if( sk == 0 )
		return notify_fail("你的御蜂術並不熟練，無法順利的吹奏蜂笛。\n");

	if( me->query("class") != "dancer" )
		return notify_fail("舞者專屬的蜂笛，你並不會使用。\n");

	if( me->query_temp("order_bee") )
		return notify_fail("儘管你不斷的吹奏著，蜂笛已經無法控制著在戰鬥中的蜜蜂。\n");

	if( target->query("no_kill") || environment(target)->query("no_fight") )
		return notify_fail("彷彿有一股神秘的力量阻止著你吹奏蜂笛。\n");

	if( target->is_corpse() || !target->is_character())
		return notify_fail("只見一群蜜蜂飛舞於"+target->name(1)+"之上，並沒有採取任何攻擊。\n");

	if( !me->is_fighting() || !target->is_fighting() )
		return notify_fail("蜜蜂無法判斷敵人，正不斷的四處亂飛中。\n");

	me->set_temp("order_bee",1);
	t_sk = (int)target->query_skill("dodge");
	if( t_sk == 0 )
		t_sk = 2;
	d_msg = HIW" 吹奏著 \n\n"NOR;
	i = random(100);

	if( random(sk) > random(t_sk) )
	{

		if( sk >= 60 && random(100) < 1 )
		{
			d_msg = d_msg + HIC+"～　"+HIG+"＠ "+HIM+"幻 曲 "+HIG+"＠  "+HIC+"～"+HIG+"  ＠  "+HIY+"蜂    王    篇"+HIG+"  ＠  "+HIW+"～\n\n"+NOR;
			if( i == 77 )
			{
				d_msg = d_msg + "     "+HIC+"	神 "+HIW+"	☆ "+HIM+"	形 "+HIW+"	☆ "+HIY+"	俱 "+HIW+"	☆ "+HIG+"	滅     \n"NOR;
				limit = (int)target->query("max_kee")/10;
				if( limit < 1500 )
					limit = 1500;
			}
			if( 90 > i > 80 )
			{
				d_msg = d_msg + "     "+HIC+"	雷 "+HIW+"	ξ "+HIM+"	蜂 "+HIW+"	ξ "+HIY+"	破 "+HIW+"	ξ "+HIG+"	魔     \n"NOR;
				limit = (int)target->query("max_gin")/10;
				if( limit < 800 )
					limit = 800;
			}
			if( 40 > i > 30 )
			{
				d_msg = d_msg + "     "+HIC+"	火 "+HIW+"	＊ "+HIM+"	蜂 "+HIW+"	＊ "+HIY+"	降 "+HIW+"	＊ "+HIG+"	妖     \n"NOR;
				limit = (int)target->query("max_sen")/10;
				if( limit < 500 )
					limit = 500;
			}
			if( i == 77 || i == 85 || i == 35 || i == 84 || i == 34 || i == 82 || i == 32 )
				d_msg = d_msg + HIY+"\n曲調一氣喝成～巨蜂展開了猛烈的攻勢～\n"+NOR;
			else
			{
				d_msg = d_msg + HIR+"\n可惜氣一走岔，笛音走偏了幾階音調～\n"+NOR;
				limit = (int)target->query("max_kee")/100;
				if( limit > 500 )
					limit = 500;
			}
			message_vision(HIW+"$N對著$n"+d_msg+"\n"+NOR,me,target);
			target->receive_wound("kee", random(limit),me);
			COMBAT_D->report_status(target);
			call_out("do_dest",4,me);
			me->start_busy(1);
			return 1;
		}
		if( sk >= 30 && random(100) < 50 )
		{
			d_msg = d_msg + HIY+"～　"+HIC+"神 調  "+HIY+"～"+HIG+"     蜂   "+HIW+"□   "+HIG+"后   "+HIW+"□   "+HIG+"律\n\n"+NOR;
			if( i >= 40 )
			{
				d_msg = d_msg +HIC"   補   精"+NOR;
				limit = (int)me->query("max_gin")/10;
				me->receive_curing("gin",random(limit));
				me->receive_heal("gin",random(limit));
			}
			if( i >= 70 )
			{
				d_msg = d_msg +HIY"   回   氣"+NOR;
				limit = (int)me->query("max_kee")/10;
				me->receive_curing("kee",random(limit));
				me->receive_heal("kee",random(limit));
			}
			d_msg = d_msg +HIM"   療   神"+NOR;
			limit = (int)me->query("max_sen")/10;
			me->receive_curing("sen",random(limit));
			me->receive_heal("sen",random(limit));
			message_vision("$N在$n面前，對著自己"+d_msg+"\n"+NOR,me,target);
			COMBAT_D->report_status(me);
			call_out("do_dest",3,me);
			return 1;
		}
		d_msg = d_msg +HIM+"‵　"+HIY+"蜂 曲　"+HIM+"′"+HIW+"	～     群     蜂     譜     ～\n\n"+NOR;
		limit = random(200)+sk;
		if( i > 70 )
		{
			d_msg = d_msg +HIM"   擾   神"+NOR;
			target->receive_damage("gin",limit,me);		
		}
		if( i > 40 )
		{
			d_msg = d_msg +HIC"   吸   精"+NOR;
			target->receive_damage("gin",limit,me);
		}
		d_msg = d_msg +HIY"   損   氣"+NOR;
		target->receive_damage("kee",limit,me);
		message_vision(HIW+"$N對著$n"+d_msg+"\n",me,target);
		COMBAT_D->report_status(target);
		call_out("do_dest",2,me);
		return 1;
	}
	else
	{
		message_vision(HIR+"$N"+HIR+"對著$n"+HIR+"吹奏著蜂笛，可惜並無呼喚出任何的蜜蜂出來。\n"NOR,me,target);
		call_out("do_dest",1,me);
	return 1;
	}
}

int do_dest(object me)
{
if(me)
me->delete_temp("order_bee");
}
