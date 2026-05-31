//排版 by blazakira 2011/8/8

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;

int sk;
void remove_effect (object me);

int perform(object me, object target)
{
  sk=me->query_skill("nine-steps",1);
  if (sk<80)
    return notify_fail ("你的技能等級尚不足使用此技能！\n");
  if (me->query ("force") < 200)
    return notify_fail ("你的內力不足！\n");
  if ((int)me->query_temp ("snake-steps", 1))
    return notify_fail ("你已經使用靈蛇幻影了。\n");
  if ( me->query("class") !="poisoner" )
    return notify_fail ("你不是魔教徒所以無法使用靈蛇幻影。\n");

  if( me->is_fighting() ) me->start_busy(1);

  message_vision ("\n"HIY"$N"NOR"神形意轉,運使出"HIG"九天靈影步法"NOR"終極奧義"HIW"ζ"HIY"靈。蛇。幻。影"HIW"ζ"NOR"\n",me,target);
  me->add ("force", -200);

  message_vision (HIM"剎時間$N整個人變得如靈蛇般靈活。\n"NOR, me,target);

  // 設這個mark後就有dodge_sp 了
  me->set_temp ("snake-steps", 1);

  me->start_call_out((: call_other, __FILE__, "remove_effect",me:),sk*2);
  return 1;
}

void remove_effect (object me)
{
  // 刪除 dodge_sp 的mark
  int fun=me->query("functions/snake-steps/level");
  me->delete_temp ("snake-steps");
  tell_object (me, NOR"妳覺得自己的身體沈重下來了。\n"NOR);
  if(fun<100) function_improved("snake-steps",random(500)+sk);
  return;
}
