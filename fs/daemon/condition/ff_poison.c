// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if(duration < 1||me->query("force")<10) {
    tell_object(me, "你的氣血漸漸順暢了。\n");
    return 0;
  }
  else {
    // 改成亂數, 並且調小一點
    me->add("force",-1*(random(me->query_skill("force",1)/10)+1));
    me->apply_condition("ff_poison",duration-1);
    tell_object(me,HIY + "你氣血失調﹐內力無法恢復。\n" + NOR);
  }
  return 1;
}
