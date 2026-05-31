#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
        if(me->query("s_kee")<10)
     {
          tell_object(me,"你的靈氣修練不夠。\n");
             return 1;
     }
     if(me->query_temp("super_god")==1) {
 tell_object(me,"你以經在使用【"HIR"血魔鬥氣"NOR"】了!!!。\n");
 return 1; }
 message_vision(
          HIW "$N一聲大喝!!身上爆出無數血光，牽動身上"HIR"血魔鬥氣"HIW"﹗\n" NOR,me);
 message_vision(
          HIY "$N的全身被血魔鬥氣所覆，發出詭異的光芒!!\n" NOR,me,target);
        if(((int)me->query("kee")) < ((int)me->query("max_kee")))
        {
        me->add("kee",1000);
        me->add("force",200);
        }
        me->set("s_kee",0);
     return 1;
}
