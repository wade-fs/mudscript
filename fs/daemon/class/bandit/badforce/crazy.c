//crazy.c
//魔道獸神變 by frequency  2003  May

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;

int exert(object me, object target)
{
  int blade,sword,exp,fun,gain,bell;
  int kee,gin,sen;
  kee = me->query("max_kee");
  gin = me->query("max_gin");
  sen = me->query("max_sen");
  blade = (int)me->query("functions/evil-blade/level");
  sword = (int)me->query("functions/ghost-sword/level");
  exp = me->query("combet_exp")/300000;
  fun = (int)me->query("functions/crazy/level");
  bell = me->query("bellicosity")/100;
  if(bell > 100)  bell = 100;
  if(exp > 100)  exp = 100;

  if(me->query("class") != "bandit" )
        return notify_fail("你不是壞人不能用。\n");
  if(!present("Evil Book",me) && fun < 100)
        return notify_fail("你以為天道魔經的魔功\可以背得起來嗎?\n");
  if(me->query_temp("crazy"))
        return notify_fail("你已經在使用了。\n");
  if(present("dragon_stone",me))       // 新增此判定防止利用crazy衝過水忍陣 by unfinished
        return notify_fail("你的邪惡的氣息被龍神水珠所封阻。\n");
  if(me->query_temp("put_water"))
        return notify_fail("你的邪惡的氣息被定水珠之力所封阻。\n");
               
  if(me->query("force") < me->query("max_force"))  me->set("force",me->query("max_force"));
  me->set("max_kee",3*kee);
  me->set("max_gin",2*gin);
  me->set("max_sen",2*sen);
  me->add("eff_kee",2*kee);
  me->add("eff_gin",gin);
  me->add("eff_sen",sen);
  me->add("kee",2*kee);
  me->add("gin",gin);
  me->add("sen",sen);
  me->set_temp("crazy",1);
  me->apply_condition("crazy",fun+10);
  if(fun < 30)
  {
   message_vision(RED"                 $N詳閱\一本血紅的古書，口中喃喃自語不知道唸些什麼。

                         "HIW"【"HIM"天道魔經"HIW"】    《"HIG"序章"HIW"》
                         
                         
                                 "HIB"魔 隨 空 而 發\n\n\n"NOR,me);
         gain = fun + 10;
         me->add_temp("apply/attack",gain);
         me->add_temp("apply/defense",gain);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, gain, fun :), fun);
         return 1;

  } else if ( fun < 65 && fun >= 30)
  {
   message_vision(RED"                 $N詳閱\一本血紅的古書，原本生機盎然的目光逐漸渙散。

                         "HIW"【"HIM"天道魔經"HIW"】    《"HIG"卷貳"HIW"》
                         
                         
                                 "HIC"魔 隨 影 而 動\n\n\n"NOR,me);
         gain = (fun + sword)/2;
         me->add_temp("apply/attack",gain);
         me->add_temp("apply/defense",gain);
         me->add_temp("apply/dodge",gain);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, gain, fun :), fun);
         return 1;
  } else if ( fun < 99 && fun >= 65)
  { 
   message_vision(RED"                 $N詳閱\一本血紅的古書，身上開始散發出陣陣陰森魔氣。

                         "HIW"【"HIM"天道魔經"HIW"】    《"HIG"卷三"HIW"》
                         
                         
                                 "HIY"魔 隨 魂 而 殺\n\n\n"NOR,me);
         gain = (fun + sword + blade)/2;
         me->add_temp("apply/attack",gain);
         me->add_temp("apply/defense",gain);
         me->add_temp("apply/parry",gain);
         me->add_temp("apply/dodge",gain);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, gain, fun :), fun);
         return 1;
  } else { 
   message_vision(RED"                 $N詳閱\一本血紅的古書，全身爆發出令人窒息的強大魔氣。

                         "HIW"【"HIM"天道魔經"HIW"】    《"HIG"終章"HIW"》
                         
                         
                                 "HIB"魔  道   "HIR"獸  神  變\n\n\n"NOR,me);
         gain = (fun + sword + exp + bell)/2;
         me->add_temp("apply/attack",gain);
         me->add_temp("apply/defense",gain);
         me->add_temp("apply/parry",gain);
         me->add_temp("apply/dodge",gain);
         me->add_temp("apply/unarmed",gain);
         me->add_temp("apply/sword",gain);
         me->start_call_out( (: call_other, __FILE__, "remove_effect", me, gain, fun :), fun);
         return 1;
         }
} 
 
void remove_effect(object me, int gain,int fun)
{ 
  me->set("max_kee",me->query("max_kee")/3);
  me->set("max_gin",me->query("max_gin")/2);
  me->set("max_sen",me->query("max_sen")/2);
  me->set("eff_kee",me->query("max_kee"));
  me->set("eff_gin",me->query("max_gin"));
  me->set("eff_sen",me->query("max_sen"));
  me->delete_temp("crazy");
  me->clear_condition("crazy");
  message_vision(HIW"$N自狂暴狀態中甦醒，恢復理性了。\n"NOR,me);
  if(fun < 30)
  {
         me->add_temp("apply/attack",-gain);
         me->add_temp("apply/defense",-gain);
  }else if ( fun < 65 && fun >= 30)
           {
         me->add_temp("apply/attack",-gain);
         me->add_temp("apply/defense",-gain);
         me->add_temp("apply/dodge",-gain);
           	
           }
   else if ( fun < 99 && fun >= 65)
           {
         me->add_temp("apply/attack",-gain);
         me->add_temp("apply/defense",-gain);
         me->add_temp("apply/parry",-gain);
         me->add_temp("apply/dodge",-gain);
           }
   else {
         me->add_temp("apply/attack",-gain);
         me->add_temp("apply/defense",-gain);
         me->add_temp("apply/parry",-gain);
         me->add_temp("apply/dodge",-gain);
         me->add_temp("apply/unarmed",-gain);
         me->add_temp("apply/sword",-gain);
        }
   if(fun < 100) function_improved("crazy",fun*2+random(300));
}


