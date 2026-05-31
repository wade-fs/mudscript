#include <ansi.h>
#include <command.h>
inherit SSERVER;
inherit F_CLEAN_UP;
void remove_effect(object me);
int perform(object me, object target)
{
   if( target != me)
   return notify_fail("¦¹­p¥u¯à¹ï¦Û¤v¥Î¡C\n");
   if( me->is_fighting())
      return notify_fail("¨S¦³¤ô...­þ¨Óªº³½ºN£«...\n");

   if( me->query_temp("defense")==1)
      return notify_fail("§A¤w¸g¦bºN³½¤F, ÁÙ¶ûºNªº¤£°÷£«...\n");

   if( me->query("sen") < 20 )
      return notify_fail("§Aªººë¯«¤O¤£°÷¡MµLªk¥Î­p¡C\n");

   if( me->query_skill("plan", 1) < 50 )
      return notify_fail("§Aªº¿Ñ²¤¯à¤O¤£°÷¡C\n");
// ¤£¬O¾§ªù
   if( me->query("family/family_name") != "¾§ªù")
    return notify_fail("¤£¬O¾§¥Í¡A¤£µ¹§A¥Î«¨¡I¡I^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("§A¨S¸Ñ¹L¤Õ©ú§LªkªºÁ¼¡A¤£µ¹§A¥Î«¨¡I¡I^_^\n");
   me->add("sen",-20);
   me->start_busy(2);           //¤£ºÞ¦³¨S¦³¦¨¥\ ¥ý delay ¦A»¡....
   me->set_temp("defense", 1);
   me->add_temp("apply/defense", me->query_skill("god-plan",1)/2);
me->start_call_out((:call_other,__FILE__,"remove_effect",me:),30);
   message_vision("$N¨Ï¥X²V¤ôºN³½¤§­p, »s³y²V¶Ã, ¥ø¹Ï¸ú¹L¼Ä¤Hªº§ðÀ»\n", me);
   return 1;
}
ÿ
void remove_effect( object me)
{
  me->delete_temp("defense");
  me->add_temp("apply/defense",-me->query_skill("god-plan",1)/2);
  tell_object( me, "³½°Ç...³½°Ç...¦n¹³¤w¸g¨S¦³³½Åý§AºN¤F...\n");
}
