#include <ansi.h>
#include <command.h>
inherit SSERVER;
inherit F_CLEAN_UP;
void remove_effect(object me);
int perform(object me, object target)
{
   if( target != me)
   return notify_fail("pu菑v峞C\n");
   if( me->is_fighting())
      return notify_fail("S...茠N...\n");

   if( me->query_temp("defense")==1)
      return notify_fail("AwgbNF, 棤N...\n");

   if( me->query("sen") < 20 )
      return notify_fail("A諯保MLk峟pC\n");

   if( me->query_skill("plan", 1) < 50 )
      return notify_fail("A挐OC\n");
// O
   if( me->query("family/family_name") != "")
    return notify_fail("O矷AA峆II^_^\n");

   me->add("sen",-20);
   me->start_busy(2);           //犌S\  delay A....
   me->set_temp("defense", 1);
  me->add_temp("apply/defense", me->query_skill("god-plan",2));
me->start_call_out((:call_other,__FILE__,"remove_effect",me:),30);
message_vision(HIC + "$N洏XVNp, Wl, W[菑v荓峔m!!\n" + NOR, me);
   return 1;
}

void remove_effect( object me)
{
  me->delete_temp("defense");
me->add_temp("apply/defense",-me->query_skill("god-plan",2));
  tell_object( me, "......nwgSANF...\n");
}
