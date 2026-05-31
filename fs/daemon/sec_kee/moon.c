// gather.c
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
int msk=me->query("max_s_kee",1);
if(msk > 1200) msk=1200;
     if(me->query("s_kee")<20)
      {
          tell_object(me,"你的靈氣不夠。\n");
          return 1;
      }

      message_vision(
         HIW + "$N靈氣浮現﹐只見一道陰柔的劍氣從$N破體衝出﹗\n" NOR,me);
         message_vision(  HIC "\n飄渺的幽幽劍氣，輕柔的穿刺過$n奇經八脈。\n"NOR,me,target);
        target->receive_damage("kee",7*me->query("max_s_kee"));

        target->start_busy(10);
        COMBAT_D->report_status(target);
      me->add("s_kee",-20);
      me->kill_ob(target);
        return 1;
}


