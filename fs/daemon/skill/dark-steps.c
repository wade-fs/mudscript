#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void reattack();
//當玩家驅動化影術得時候，會出現前三招(或許會在加)
//然後玩家趨到分功術的時候，會出現後三招
string *dodge_msg = ({
    "$n身影微動,已經藉一招「" + HIC + "幻影幢幢" + NOR + "」繞到$N四周形成四個幻影。\n",
    "$n身形一轉使出「" + HIC + "縮  地" + NOR + "」瞬時人離原位而避了開去,$N擊中了幻影。\n",
    "只見$n身影一晃即失,一式「" + HIC + "瞬天影舞" + NOR + "」已幻化在三丈之外。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

string query_dodge_msg(string limb)
{
   int x=0,sk_lv=1,now_exp,skrate;
   object target,me=this_player();
   
   if(!me) return "";
   target=offensive_target(me);
//其實當dodge發動時，就已經代表沒有受到傷害
//而且對於太強的對手來說，dodge發動的機率並不高
//所以，第一是為了下一次作準備，第二是作一些基本強化   

   if (me->query_temp("step-shadow"))
   {//代表玩家使用化影術
   	if (me->query("dark-steps/shadow/exp"))
   	{//檢查玩家是否第一次使用化影術
        	 me->add("dark-steps/shadow/exp",1);
        	 now_exp=me->query("dark-steps/shadow/exp");
        	 sk_lv=me->query("dark-steps/shadow/lv");
        	 if ( now_exp > (20*sk_lv))
        	 {//作升級檢查
        	 	me->set("dark-steps/shadow/exp",1);
        	 	if (me->query("dark-steps/shadow/lv") < 100)
        	 		me->add("dark-steps/shadow/lv",1);
        	 	now_exp=0;
        	 }
        }
   	else
   	{
   		 me->set("dark-steps/shadow/lv",1);
        	 me->set("dark-steps/shadow/exp",1);
        }
   	sk_lv=me->query("dark-steps/shadow/lv");
   	switch (sk_lv)
   	{
		case 0..10://玩家將有40%~50%的機率發動化影身法
			skrate= random (100)+ sk_lv +1;
			if (skrate > 60)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				me->set_temp("shadowfun",2);
message_vision(HIW + "\n            分	 功\	 化	 影	 身	 法!" + NOR,target);
message_vision(HBMAG + "\n              分		影		術   \n" + NOR,target);
			}
			break;
		case 11..40://玩家將有40%~70%的機率發動化影身法
			skrate= random (100)+ sk_lv +1;
			if (skrate > 70)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				    
				me->set_temp("shadowfun",2);
				me->receive_heal("gin",skrate+50);
      				target->receive_wound("gin",skrate+50,me);
message_vision(HIW + "\n            分	功\	化	影	身	法!" + NOR,target);
message_vision(HBMAG + "\n              分		影		術   \n" + NOR,target);
message_vision(HBYEL + "\n$N幻出許\多身影，令$n眼花撩亂，無法分清楚何者是實體\n" + NOR,me,target);
			}
			break;
		case 41..70://玩家將有40%~70%的機率發動化影身法
			skrate= random (100)+ sk_lv - 40;
			if (skrate > 60)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				//用set是避免玩家連續發動後累加上去				    
				me->set_temp("shadowfun",3);
				me->delete_busy();
				target->receive_wound("gin",skrate+100,me);
message_vision(HIW + "\n            分	功\	化	影	身	法!" + NOR,target);
message_vision(HBMAG + "\n              分		影		術   \n" + NOR,target);
message_vision(HBYEL + "\n$N幻出許\多身影，令$n眼花撩亂，無法分清楚何者是實體 \n" + NOR,me,target);
message_vision(HBCYN + "\n剎那間，整個空間中都是$N的身影，$n有點暈頭轉向了\n" + NOR,me,target);
			}
			break;
		case 71..100://玩家將有60%~80%的機率發動化影身法
			skrate= random (100)+ sk_lv - 70;
			if (skrate > 40)
			{
				if (me->query("atman") > 30)
				    me->add("atman",-30);
				else
				    me->set("atman",0);
				//用set是避免玩家連續發動後累加上去				    
				me->set_temp("shadowfun",3);
				me->delete_busy();
				target->start_busy(1);
				me->receive_heal("gin",sk_lv);
				me->receive_heal("sen",sk_lv);				
      				target->receive_wound("gin",sk_lv*2+30,me);
      				target->receive_wound("sen",sk_lv*2+30,me);
message_vision(HIW + "\n            分	功\	化	影	身	法!" + NOR,target);
message_vision(HBMAG + "\n              分		影		術   \n" + NOR,target);
message_vision(HBYEL + "\n   $N幻出許\身影，令$n眼花撩亂，無法分清楚何者是實體\n" + NOR,me,target);
message_vision(HBCYN + "\n   剎那間，整個空間中都是$N的身影，$n有點暈頭轉向了\n" + NOR,me,target);
message_vision(HBRED + "\n   $N的身影越幻化越多，彷彿整個空間為之牽動........\n" + NOR,me,target);
			}
			break;
		case 101..150://特別等級，只有獲得獎勵的玩家才有可能 90% 機會
			if (random(100) < 90)
			{//專家級僅是發動機率變高，傷害公式計算那裡，會有新高點
				if (me->query("atman") > 100)
				    me->add("atman",-100);
				else
				    me->set("atman",0);
				//用set是避免玩家連續發動後累加上去				    
				me->set_temp("shadowfun",3);
				me->delete_busy();
				target->start_busy(1);
				me->receive_heal("gin",sk_lv);
				me->receive_heal("sen",sk_lv);				
      				target->receive_wound("gin",sk_lv*2+30,me);
      				target->receive_wound("sen",sk_lv*2+30,me);
message_vision(HIW + "\n            專		家		級" + NOR,target);
message_vision(HIW + "\n            分	功\	 化	 影	 身	 法!" + NOR,target);
message_vision(HBMAG + "\n               分		影		術   \n" + NOR,target);
message_vision(HBYEL + "\n   $N幻出許\身影，令$n眼花撩亂，無法分清楚何者是實體\n" + NOR,me,target);
message_vision(HBCYN + "\n   剎那間，整個空間中都是$N的身影，$n有點暈頭轉向了\n" + NOR,me,target);
message_vision(HBRED + "\n   $N的身影越幻化越多，彷彿整個空間為之牽動........\n" + NOR,me,target);
			}
			break;

		default://巫師級(超過限制)     有100%的機率發動化影身法
			{
message_vision(HIW + "\n            巫		師		級" + NOR,target);
message_vision(HIW + "\n            分	功\	化	影	身	法!" + NOR,target);
message_vision(HIY + "\n   $N幻出許\身影，令$n眼花撩亂，無法分清楚何者是實體\n" + NOR,me,target);
message_vision(HIR + "\n   剎那間，整個空間中都是$N的身影，$n有點暈頭轉向了\n" + NOR,me,target);
message_vision(HIG + "\n   $N的身影越幻化越多，彷彿整個空間為之牽動........\n" + NOR,me,target);
				me->set_temp("shadowfun",4);
				me->delete_busy();
				target->start_busy(2);
				me->receive_heal("gin",sk_lv*5);
				me->receive_heal("sen",sk_lv*5);
      				target->receive_wound("gin",sk_lv*2+30,me);
      				target->receive_wound("sen",sk_lv*2+30,me);
      				me->set_temp("power-down",17);
			}
			break;
	}					
	return dodge_msg[random(3)];		
   }
   if (me->query_temp("step-share"))
   {//代表玩家使用分功術
    //目前暫時沒有做這一部分，應該會等到比較後面的故事再弄
   	if (me->query("dark-steps/share/exp"))
   	{
        	 me->add("dark-steps/share/exp",1);
        	 now_exp=me->query("dark-steps/share/exp");
        	 sk_lv=me->query("dark-steps/share/lv");
        	 if ( now_exp > (20*sk_lv))
        	 {//作升級檢查
        	 	me->set("dark-steps/share/exp",1);
        	 	me->add("dark-steps/share/lv",1);
        	 	now_exp=0;
        	 }
        }
   	else
   	{
        	 me->set("dark-steps/share/exp",1);
        	 me->set("dark-steps/share/lv",1);
        }
   	sk_lv=me->query("dark-steps/share/lv");
   }   
   return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
tell_object(me,"分功\化影無法從學習中獲得進展, 必須自己修行方有成果!!\n");
return 0;
}
string perform_action_file(string action)
{
        return CLASS_D("killer")+"/dark-steps/"+action;
}



