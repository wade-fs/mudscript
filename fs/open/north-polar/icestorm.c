#include <ansi.h>
/*因為def-cold比較麻煩，所以讓def-cold後的傷害略小於穿禦寒eq的
新增加羊毛大衣可以抵禦凍氣的設定 by Alucard 2009 Sep*/
void init()
{
	object me,ob,obj,mob;
	int kee,i,j;
	me = this_player();
  if(me->query_temp("def_cold1")) return;
	kee = me->query("max_kee");
        j = me->query_temp("polar/kill");
        j = j/3;
        if( 25 > random(me->query_kar()) && me->query("family/family_name") != "北極圈")
	   {
	    tell_object(me,HIC + "一陣巨大的暴風雪高速呼嘯而過，你頓時陷入凜冽的凍氣之中，牙齒格格作響!!\n" + NOR);
           if(me->query_temp("def_cold"))
                {
	            message_vision(YEL + "$N身上的凍氣訣和冰雪隱隱抗衡，一股暖流遊走全身，減弱了風暴的寒勁。\n" + NOR,me);
	            me->receive_damage("kee",kee/31);
	            }
           else if(present("light-ring",me) && present("light-ring",me)->query("equipped"))
                {
	            message_vision(YEL + "一道柔和的光芒閃現，溫暖的靈氣在$N身上流轉，減弱了風暴的寒勁。\n" + NOR,me);
	            me->receive_damage("kee",kee/30);
	            }
		   else if(present("sheep-cloth",me) && present("sheep-cloth",me)->query("equipped"))
                {
	            message_vision(YEL + "暖烘烘的羊毛皮包覆著$N身上的熱量，有效地減弱了風暴的寒勁。\n" + NOR,me);
	            me->receive_damage("kee",kee/30);
	            }
                else 
	            {
	            me->start_busy(1);
	            me->receive_wound("kee",kee/12);
	            if(random(10) == 3)  me->apply_condition("cold",random(3)+5);
	            }
	     COMBAT_D->report_status(me,1);
	   } 

	  if( j > 7 && random(j) > 4)
	  {
	    if(j > 12)  j = 12;
	    message_vision(HIY + "一群企鵝跑出來向$N大聲咆嘯著，牠們對於$N恣意屠殺他們朋友的行為非常不滿!!\n" + NOR,me); 
	    for(i=0 ; i<j-3 ; i++)
	     {
	      mob = new(__DIR__"npc/mob5");
	      mob->move(environment(me));
	      mob->command("follow "+me->query("id"));  
	      mob->kill_ob(me);
	     }
	     me->start_busy(1);
	     me->delete_temp("polar/kill");
	  }
	//me->set("startroom",environment(me));
	return ;
}
