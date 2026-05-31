#include <ansi.h>
// By Sueplan 策免計 - 儒門本身不怕計謀
//考濾要不要加call_out時間讓plan的temp消掉
//這個計謀只能用來擋諸葛神算的plan, 不能擋sixgod-plan

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
*************************************************************************************/

inherit SSERVER;
object me=this_player();
int perform(object me,object target)
{
		if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
        if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
		if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
		if( me->query("sen") < 100 )
                return notify_fail("你的精神不夠﹐無法使用。\n");
        if( target != me ) 
                return notify_fail("此計只能對自己用。\n");
        if(me->is_fighting(target))     
                return notify_fail("策免計只能在戰鬥前使用。\n");
        if( me->query("force") < 2500 )
                return notify_fail("以你的內力不足以用此計。\n");
        if( me->query_temp("no-plan") == 1 )
			return notify_fail("你已經使出策免計了。\n");
		message_vision(HIY"$N以六韜奇略中的策免計，使自己更容易見破敵人的計謀。\n"NOR,me);
        me->set_temp("speed",100);
        me->set_temp("empty",100);
        me->set_temp("mount",1);
        me->set_temp("false",100);
        me->set_temp("lock-link",100);
        me->set_temp("ghost",1);
        me->set_temp("rob",100);  
        me->set_temp("no-plan",1);
        me->add("force",-2000);
        return 1;
}
