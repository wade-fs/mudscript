//By sueplan取走敵人的weapon - 草船借箭 2000.7.27
//修改為對同一個敵人只能用三次 by sueplan

/*************************************************************************************
修改 By Kalin (2003-06-17)
a.增加限制-解過儒尊
b.增加限制-exp>500萬
*************************************************************************************/

//修改為可對玩家使用，但無法偷盜稀有武器 by frequency 2003 7/29
#include <ansi.h>
inherit SSERVER;
int delwap(object me);
int perform(object me, object target)

{
        object ob=this_object();
        object ewp;
        int i;
		if( !me->query("quests/god-plan"))
			return notify_fail("你沒解過孔明兵法的謎，不給你用咧！！^_^\n");
        if(!me->query("mark/sixgod-plan"))
			return notify_fail("你還沒解過『六韜奇略』!");
		if(me->query("combat_exp")<5000000)
			return notify_fail("你的經驗值不夠!");
		if( !target ) target = offensive_target(me);
        if( !me->is_fighting(target) )
			return notify_fail("草船借箭只能在戰鬥中使用。\n");
		ewp=target->query_temp("weapon");
if(!ewp) return notify_fail("你東摸摸，西摸摸，什麼也沒有摸到！\n");
        if( ewp->query("no_steal") || ewp->query("no_give") || ewp->query("no_get"))
                        return notify_fail("敵人將兵器緊緊握住，使你無從下手。\n");
        if(!ewp)
			return notify_fail("敵人手中並沒有兵器。\n");
        if( me->query("force") < 500 )
			return notify_fail("你的內力不夠。\n");
        if( me->query("kee") < 300 )
			return notify_fail("你的氣不夠。\n");
        if( me->query_temp("getwap") == 1 )
			return notify_fail("你剛用完此計，馬上用是會被對方看破的。\n");
		
		message_vision(HIG"面帶微笑，似乎$n的舉動已在欲料之中。\n"NOR,me,target);
		message_vision(HIY"只見$N貼近$n的兵器，一晃身劃向他的兵器。\n"NOR,me,target);
        if( environment(me) == environment(target) ) 
          i=random(100);
          if( i > 50 )
          {
			  ewp->unequip();
			  message_vision(HIR"$N以迅雷不及掩耳之速運用六韜奇略中草船借箭的功\夫，結果$n殊不知手中的"+ewp->query("name")+HIR"已被取走。\n"NOR,me,target);
			  ewp->set("value",1);
			  ewp->move(me);
			  target->rest_action();
          } 
        else 
        {
			message_vision(HIC"但是卻見$N的雙手無法處及$n的兵器。\n"NOR,me,target);
			me->add("kee",-100);
        }
        me->set_temp("getwap",1);
        me->add("force",-500);
        call_out("delwap",5,me);
        //為了必免連用太扯所加的DELAY TIME
        return 1;
}
int delwap(object me)
{
        if(me)
		{
			me->delete_temp("getwap");
        }
        return 1;
}



