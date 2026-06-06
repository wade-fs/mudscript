//劍傷 by Dico
#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) return 0;
tell_object(me,HIR
"你的劍傷復發，傷口被氣勁侵蝕入骨，嚴重出血！\n"NOR);
message("vision",HIR+me->name()+"傷口發作紅腫，一個蒼狼跌倒在地！\n"NOR,environment(me),me);
if(me->is_fighting())
me->start_busy(1);
me->receive_wound("kee",30);
me->receive_damage("kee",30);
if(me->query("force")<0) me->set("force",0);
me->apply_condition("blade",duration-1);
if(duration<1) return 0;
return 1;
}
