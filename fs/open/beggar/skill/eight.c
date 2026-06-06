#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object ob;
        string *name;

        if( !target ) target = offensive_target(me);

        if(me->query_skill("dragonforce",1) < 50 )
              return notify_fail("你的降龍心法不夠純熟﹐使出八方風雨\n");
        if( (string)me->query_skill_mapped("force")!= "dragonforce")
                return notify_fail("八方風雨須配合降龍心法才能用。\n");
if(!(ob=me->query_temp("weapon"))||(string)ob->query("skill_type")!="staff")
       return notify_fail("只有在拿棒子才能使用喔。\n");
          if(me->query("force")<300)
                           return notify_fail("你的內力不夠。\n");
                  if(me->query("kee")<200)
                           return notify_fail("你的氣不夠。\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"八方風雨只在戰鬥中才能使用。\n");
                return 0;
        }
       if(me->query("force")<300)
                           return notify_fail("你的內力不夠。\n");
                  if(me->query("kee")<200)
                           return notify_fail("你的氣不夠。\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"八方風雨只在戰鬥中才能使用。\n");
                return 0;
        }
        message_vision(
HIR"$N忽然向天怒吼,形化八方、棒化風雨使出打狗棒法之絕學"HIW"「八方風雨」"HIR"只見$N揮舞棒子,越舞越快形成無數的棒影\n"NOR,me,target);
        {
        message_vision(
            HIW"只見天地變色、漫天的棒影鋪天蓋地般向$n襲去\n"NOR,me,target);
            me->add("kee",-30);
             me->add("force",-(100 + ((int)me->query_skill("dragonforce",1)))*3)
;
        if(random(me->query_skill("staff")+20)>random(target->query_skill("dodge
")))
        {
 message_vision(
HIR"\n$n面對漫天的棒勢無法躲避,被無數的棒子擊中要害,棒棒致命、痛苦異常!!!\n"NOR,me,target);
                message_vision( NOR,me);
target->receive_wound("kee",me->query_skill("pd-staff",1)*3+random(me->query_skill("dragonforce",1)*2));
                COMBAT_D->report_status(target);
        }
        else
      {
                message_vision(
HIW"$n看出棒勢的漏洞，千均一髮之際,躲過『八方風雨』的攻擊!!!\n"NOR,me,target);
                message_vision( NOR,me);
       }
        message_vision(
            "『八方風雨』使用後，$N大耗氣力、運功調息，無法移動\n",me,target);
        me->start_busy(2);
        me->kill_ob(target);
          function_improved("eight",random(me->query("force")/10));
        message_vision( NOR,me);
        return 1;
  }
}
