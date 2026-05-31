//Written By AceLan 98.7.22 ¶X¤õ¥´§T¤§­p...
// §ï¬°¥i­«½Æ¨Ï¥Î¡A¤£¹L©R¤¤²v³v¦¸­°§C¡C by frequency 2003 7/29
#include <ansi.h>

int perform(object me, object target)
{
   if( !target ) return notify_fail("§A­n¹ï½Ö¥Î­p¡H\n");

   if( !target->is_fighting() || !target->is_killing())
      return notify_fail("¶X¤õ¥´§T¤§­p¥u¯à¶X¼Ä¤H³´¤J¦M¾Ô¤§®É¡A¶X¨ä¤£³Æ¡Aµo°Ê§ðÀ»¡C\n");

   if( me->is_fighting() || me->is_killing())
      return notify_fail("ªdµÐÂÄ¹L¦¿¡A¦Û¨­Ãø«O¤F¡A«ç»òÁÙ·|¦³¾l¤O¨Ó¶X¤õ¥´§T©O¡H\n");

   if( me->query("sen") < 20 )
      return notify_fail("§Aªººë¯«¤O¤£°÷¡MµLªk¥Î­p¡C\n");

/*if(target->query_temp("rob")==1)
return notify_fail("¦P¤@­p¿Ñ¥u¯à¥Î¤@¦¸¡I¡I\n");*/
   if( me->query_skill("plan",1) < 30)
      return notify_fail("§Aªº¿Ñ²¤¯à¤O¤£°÷¡C\n");
// ¤£¬O¾§ªù
   if( me->query("family/family_name") != "¾§ªù")
    return notify_fail("¤£¬O¾§¥Í¡A¤£µ¹§A¥Î«¨¡I¡I^_^\n");
	if( !me->query("quests/god-plan"))
		return notify_fail("§A¨S¸Ñ¹L¤Õ©ú§LªkªºÁ¼¡A¤£µ¹§A¥Î«¨¡I¡I^_^\n");
   me->start_busy(1);
   me->add("sen",-20);
   if(random(5+target->query_temp("rob")) < 4)
   {
    target->start_busy(4);
    target->add_temp("rob",1);
      message_vision("$N¨Ï¥X¶X¤õ¥´§T¤§­p, ¶X¼Ä¤§¦M, ´N¶Õ¨ú§Q, ¦V¼Ä¤Hµo°Ê²r§ð\n", me);
      me->kill_ob( target);
   }else{
	      message_vision( HIG + @LONG
$nÃÑ¯}¤F$Nªº¶X¤õ¥´§T¤§­p¡M²±«ã¤§¤U®i¶}²r§ð¡C
LONG + NOR ,me , target );
              target->kill_ob(me);
	      }
   return 1;
}
ÿ
