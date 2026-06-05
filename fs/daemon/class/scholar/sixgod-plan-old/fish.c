#include <ansi.h>
#include <command.h>
inherit SSERVER;
inherit F_CLEAN_UP;
void remove_effect(object me);
int perform(object me, object target)
{
   if( target != me)
   return notify_fail("puۤvΡC\n");
   if( me->is_fighting())
      return notify_fail("S...ӪN...\n");

   if( me->query_temp("defense")==1)
      return notify_fail("AwgbNF, ٶN...\n");

   if( me->query("sen") < 20 )
      return notify_fail("A믫OMLkέpC\n");

   if( me->query_skill("plan", 1) < 50 )
      return notify_fail("AѲOC\n");
// O
   if( me->query("family/family_name") != "")
    return notify_fail("O͡AAΫII^_^\n");

   me->add("sen",-20);
   me->start_busy(2);           //ަS\  delay A....
   me->set_temp("defense", 1);
  me->add_temp("apply/defense", me->query_skill("god-plan",2));
me->start_call_out((:call_other,__FILE__,"remove_effect",me:),30);
message_vision(HIC + "$NϥXVNp, Wl, W[ۤvӱΨm!!\n" + NOR, me);
   return 1;
}

void remove_effect( object me)
{
  me->delete_temp("defense");
me->add_temp("apply/defense",-me->query_skill("god-plan",2));
  tell_object( me, "......nwgSANF...\n");
}
