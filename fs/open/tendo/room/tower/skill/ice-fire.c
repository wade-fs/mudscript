///寒冰烈火勁
#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
        int g,force;
        g = me->query_skill("gforce");
        force = me->query("force");
        if( !me->query("marks/ice-fire"))
                return notify_fail("不管你如何運氣,就是使不出來寒冰烈火勁。\n");
        if( me->query("family/family_name")!="天道派")
        return notify_fail("你忽冷忽熱,開始發羊癲瘋!\n");
        if( me->query_skill_mapped("force")!="gforce" )
        return notify_fail(HIY"hmm ～ 你用的是什麼心法啊!。\n"NOR);
        if( me->query_skill("gforce",1)<50 )
                return notify_fail("你的紫星河還不夠純熟。\n");
        if( force<200 )
                return notify_fail("你的內力不足以運起寒冰烈火勁。\n");
        if( !target ) target = offensive_target(me);
     if(target->is_busy())
     return notify_fail("敵人 BUSY 中，快攻擊吧！\n");
      message_vision(HIB+
"              $N怒氣狂提，不顧身上的傷口，不斷地將內力運至十二成。\n        
                          "HIR"$N身上發出一股強大的殺意\n
                 "HIY"$N的全身開始聚起強烈的"HIW"寒冰"HIW"與"HIR"烈火"HIY"兩道環身氣勁，\n
                   "HIW"～ 兩道氣勁源源不斷的向手上凝聚！ ～\n
                              "HIY"倏地$N大喝一聲\n
              "HIY"左手使出一招"RED"天書"MAG"絕學"HIY"中之終極奧義 - -"HIW"寒 冰 勁"HIY"–-\n
              "HIC"右手一翻使出"RED"天書"MAG"絕學"HIC"中之武學祕技 ～～"HIR"烈 火 勁"HIC"～～ \n　
                  "HIB"只見寒冰與烈火兩道氣勁如狂風暴雨般地擊向對手\n
                     "HIW"此乃天書之不秘之傳"HIC" 『"HIW"寒冰"HIR"烈火"HIW"勁"HIC"』\n"+NOR,me,target);

        me->add("force", -g*2);
 if(random(g)>random(target->query_skill("dodge",1)))
               {
   target->start_busy(2);
 target->add("kee",-2*g);
 target->apply_condition("blockade",3);
                message_vision(HIR"$n閃躲不及,被寒冰烈火兩道氣勁透體而過,全身上下被烈火及寒冰包圍著,不停的嘶吼!\n"NOR,me,target);
                COMBAT_D->report_status(target);
               }
       else
               {
                message_vision(HIM"$n急運內功\，消解了$N寒冰及烈火這兩道的氣勁。\n"NOR,me,target);
               }
        me->start_busy(1);
        return 1;
}


