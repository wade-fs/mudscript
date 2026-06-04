//背水之計 by sueplan 輔助型

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
*************************************************************************************/

#include <ansi.h>
object me=this_player();
int perform(object me, object target)
{
        int sk;
        sk=me->query_skill("plan",1);
		if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
        if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
		if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
		if( target != me)   
			return notify_fail("此計只能對自己用。\n");
        if(me->query("family/family_name")!="儒門")
			return notify_fail("你不是儒門的不能用。\n");
        if( me->query("force") < 1000 )
			return notify_fail("你的內力不夠。\n");
        if( me->is_fighting() )
			return notify_fail("戰鬥中不能使用。\n");
        if(me->query_temp("no-fear")== 1 )
			return notify_fail("你背水一戰已提高士氣了。\n");
		message_vision(HIG + "$N高聲大喊，看破生死盡力一戰。\n" + NOR,me);
        me->set_temp("oldenforce",me->query("force_factor"));
        me->set("force_factor",10+5);
        me->add("force",-500);
        me->add_temp("apply/dodge",-20);
        me->add_temp("apply/move",-20);
        me->add_temp("apply/attack",sk);
        me->set_temp("no-fear",1);
        me->add("force",-500);
        me->add("bellicosity",-5);

        return 1;
}
