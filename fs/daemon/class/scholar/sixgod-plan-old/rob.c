//Written By AceLan 98.7.22 XTp...

#include <ansi.h>

int perform(object me, object target)
{
   if( !target ) return notify_fail("An֥έpH\n");

   if( !target->is_fighting() || !target->is_killing())
      return notify_fail("XTpuXĤHJMԤɡAX䤣ơAoʧC\n");

   if( me->is_fighting() || me->is_killing())
      return notify_fail("dĹLAۨOFAٷ|lOӶXTOH\n");

   if( me->query("sen") < 20 )
      return notify_fail("A믫OMLkέpC\n");

if(target->query_temp("rob")==1)
return notify_fail("P@pѥuΤ@II\n");
   if( me->query_skill("plan",1) < 30)
      return notify_fail("AѲOC\n");
// O
   if( me->query("family/family_name") != "")
    return notify_fail("O͡AAΫII^_^\n");
   me->add("sen",-20);
   target->start_busy(3);
  target->set_temp("rob",1);
      message_vision(HIY + "$NϥXXTp, XĤM, NըQ, VĤHoʲr\n" + NOR, me);
      me->fight_ob( target);
   return 1;
}

