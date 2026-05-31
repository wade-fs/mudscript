//增加判斷玩家是否存在 by blazakira 2011/10/29

#include <ansi.h>

int update_condition(object me, int duration)
{
  if( !me ) return 1;
  else if( duration < 1  )
  {
    me->delete("age_young");
    me->add("mud_age",me->query("new_age"));
    me->delete("new_age");
    message_vision(HIC"$N的面貌瞬間\蒼\老\許\多\，行動也漸漸緩慢。\n"NOR,me);
    return 0;
  }
  me->apply_condition("young",duration-1);
  return 1;
}
