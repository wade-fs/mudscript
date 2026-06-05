//By sueplan取走敵人的weapon - 運天行道 2000.7.27

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
c.增加me->add_temp("apply/defense",sk)
d.增加損失的force
*************************************************************************************/

#include <ansi.h>
inherit SSERVER;
object me=this_player();
int perform(object me, object target)
{
	    int sk=me->query_skill("plan",1);
		if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
        if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
		if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
		if( me->query("force") < 1000 )
			return notify_fail("以你的內力不足以用此計。\n");
        if( target != me)   
			return notify_fail("此計只能對自己用。\n");
        if( me->is_fighting() )
			return notify_fail("戰鬥中不能使用。\n");
        if( me->query_temp("usesky") == 1 )
			return notify_fail("天時地利人合已經被你掌握住了。\n");
		message_vision(HIC + "$N以六韜奇略中的觀星說文之計，將自己立於不敗之地。\n" + NOR,me);
		message_vision(HIC + "$N感到自己刺術技巧又更上一層了。\n" + NOR,me);
        me->add_temp("apply/stabber",30);
		me->add_temp("apply/defense",sk);
        me->set_temp("usesky",1);
        me->add("force",-1000);
        return 1;
}




