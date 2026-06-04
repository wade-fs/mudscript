#include <ansi.h>
int update_condition(object me, int duration)
{
if(duration==0) return 0;
tell_object(me,HIR + "你的刀傷復發，傷口被氣勁侵蝕入骨，嚴重出血！\n" + NOR);
message("vision",HIR+me->name()+"刀傷發作紅腫，頓時全身無力，坐倒在地！\n" + NOR,environment(me),me);
if(me->is_fighting()) me->start_busy(1);
me->receive_wound("kee",250);
me->apply_condition("blade",duration-1);
if(duration<1) return 0;
return 1;
}
