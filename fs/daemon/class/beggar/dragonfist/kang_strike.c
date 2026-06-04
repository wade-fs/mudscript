
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

        if(me->query_skill("dragonfist",1) < 50 )
              return notify_fail("你的降龍絕學不夠純熟﹐無法聚勁於指\n");
        if( (string)me->query_skill_mapped("force")!= "dragonforce")
                return notify_fail("戰龍指必須配合降龍心法才能用。\n");
         
      if(!(ob=me->query_temp("weapon"))) 
        { if(me->query_temp("secondary_weapon"))
return notify_fail("要空手才能使用戰龍指!!!\n");}
        if(ob=me->query_temp("weapon")) 
        {
if((string)ob->query("skill_type") != "unarmed")
return notify_fail("要空手才能使用戰龍指!!!!\n");

          }
          if(me->query("force")<400)
                           return notify_fail("你的內力不夠。\n");
                  if(me->query("kee")<200)
                           return notify_fail("你的氣不夠。\n");

        if(!me->is_fighting())  
        {
                tell_object(me,"戰龍指只在戰鬥中才能使用。\n");
                return 0;
        }
        message_vision(
         HIB + "$N忽然氣勁暴漲，使出降龍絕學中的" + RED + "「戰龍指」" + HIB + "只見$N身旁真氣怒濤，降龍勁充斥在$N的指上\n" + NOR,me,target);
        {
        message_vision(
            HIW + "$N低吼一聲，無形的指勁向$n狂射而出!!" + NOR,me,target);
            me->add("kee",-30);
             me->add("force",-(100 - ((int)me->query_skill("dragonforce",1)))*3);
        if(random(me->query_skill("unarmed")+20)>random(target->query_skill("dodge")))
        {
                message_vision(
                 HIR + "\n$n躲避不及﹐指勁擊中﹐霎時$N的內勁在$n身上亂竄，痛苦異常﹗\n" + NOR,me,target);
                message_vision( NOR,me);
                  target->receive_wound("kee",me->query_skill("dragonfist",1)*3+random(me->query_skill("dragonforce",1)*2));
                COMBAT_D->report_status(target);
        }
        else
      {
                message_vision(
                HIW + "$n看出氣指方向,千均一髮一際,躲過『戰龍指』攻擊!!\n" + NOR,me,target);
                message_vision( NOR,me);
       }
        message_vision(
            "『戰龍指』射出後，$N大耗內勁、運功調息，無法移動\n",me,target);
        me->start_busy(2);
        me->kill_ob(target);
          function_improved("kang_strike",random(me->query("force")/10));
        message_vision( NOR,me);
        return 1;
  }
}
