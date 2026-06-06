
// keng_kee.c

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object ob;
        string *name;

        if( !target ) target = offensive_target(me);

          if(me->query_skill("haoforce",1) < 100 - ( me->query_con() + me->query_cps()*1.2 ) )
             return notify_fail("你的浩日心法不夠純熟﹐無法聚氣指尖。\n");
        if( (string)me->query_skill_mapped("unarmed")!= "lungshan")
                return notify_fail("浩日罡氣必須配合瀧山絕學才能用。\n");
         
      if(!(ob=me->query_temp("weapon"))) 
        { if(me->query_temp("secondary_weapon"))
          return   notify_fail("不空手怎麼發浩日訣?\n");} 
        if(ob=me->query_temp("weapon")) 
        {
         if((string)ob->query("skill_type") != "unarmed") 
            return   notify_fail("不空手怎麼發浩日訣?\n");
          }
          if(me->query("force")<250)
                           return notify_fail("你的內力不夠。\n");
                  if(me->query("kee")<180)
                           return notify_fail("你的氣不夠。\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"浩日罡\氣唯在戰鬥中才能使用。\n");
                return 0;
        }
        message_vision(
            "$N口中唸唸有詞，運起浩日心法中的「烈日訣」\n
               $N霎時一股至陽剛烈的真氣充塞著$N身旁只見$N\n
               全身發光炙熱，指尖聚集一顆明亮的光球\n\n",me,target);

        {
        message_vision(
            "$N運勁指尖，一道「浩日罡\氣」射去﹗\n",me,target);

            me->add("kee",-50);
                  me->add("force",-(110 - ((int)me->query_skill("haoforce",1)))*3);
        if(random(me->query_skill("unarmed")+20)>random(target->query_skill("dodge")))
        {
                message_vision(
                    "\n$n躲避不及﹐被罡\氣擊中﹐霎時烈火籠罩$n全身﹐嘶嚎不斷﹗\n",me,target);
                message_vision( NOR,me);
                target->apply_condition("burn",random(10) +((int)me->query_skill("haoforce", 1)/8 ));
                  target->receive_wound("kee",me->query_skill("haoforce",1)*4+random(me->query_skill("haoforce",1)*2));
                COMBAT_D->report_status(target);
        }
        else
      {
                message_vision(
                "$n運功\避開﹐但仍受罡\氣擦過﹐只見$n的傷口焦黑一塊。\n",me,target);
                message_vision( NOR,me);
                target->apply_condition("burn",random(10) +((int)me->query_skill("haoforce", 1)/8 ));
                COMBAT_D->report_status(target);
       }
        message_vision(
            "「浩日罡\氣」射出後，$N大耗內力、氣息紊亂，無法移動\n",me,target);
        me->start_busy(2);
        me->kill_ob(target);
          function_improved("kang_kee",random(me->query("force")/10));
        message_vision( NOR,me);
        return 1;
  }
}
