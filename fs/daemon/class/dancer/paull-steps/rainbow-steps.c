#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int sk;
void remove_effect (object me);
int perform(object me, object target)
{
sk=me->query_skill("paull-steps",1);
if (sk<80)
     return notify_fail ("妳的技能等級尚不足使用此技能!\n");
  if (me->query ("force") < 50)
     return notify_fail ("妳的內力不足!\n");
  if ((int)me->query_temp ("rainbow-steps", 1))
     return notify_fail ("妳已經使用七彩幻夢了。\n");
  if ( me->query("class") !="dancer" )
     return notify_fail ("妳不是舞者無法使用七彩幻夢。\n");

if( me->is_fighting() ) me->start_busy(1); //在戰鬥中使用,要busy自己一回合 by chan

  message_vision ("\n" + HIW + "$N" + NOR + "結合月影微步與夜夢天舞的精要縱身飛起使出終極舞步" + HIM + "「七彩幻夢」" + NOR + "\n",me,target);
  me->add ("force", -50);

       
  message_vision (HIG + "剎時間$N整個人變的身輕如燕。\n" + NOR, me,target);

// 設這個mark後就有dodge_sp 了
  me->set_temp ("rainbow-steps", 1);
   
  me->start_call_out((: call_other, __FILE__, "remove_effect",me:),sk*2);

  return 1;
}

void remove_effect (object me)
{
// 刪除 manashield   
int fun=me->query("functions/rainbow-steps/level");
  me->delete_temp ("rainbow-steps");
  tell_object (me, NOR + "妳覺得自己的身體沈重下來了。\n" + NOR);
  if(fun<100) function_improved("rainbow-steps",random(500)+sk);   
  return;
}
