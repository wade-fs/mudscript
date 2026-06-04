#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_FUNCTION;
inherit SSERVER;
void remove_effect (object me);
int fun;
int exert(object me, object target)
{
  int sk;
  sk=me->query_skill("iceforce",1);
  fun=me->query("functions/flyarrow/level");
  if (sk < 50)
  return notify_fail ("你的冰心訣還不到三十級﹐無法使出御箭飛行。\n");
  if(me->query("family/family_name")!="射日派") 
  return notify_fail("你不是射日派弟子, 無法使出御箭飛行");
  if (me->query ("force") < 200)
  return notify_fail ("你的內力不足﹐無法使出御箭飛行。\n");
  if (me->query_temp ("flyarrow")==1)
  return notify_fail ("你已經在御箭飛行了。\n");
/* if(fun<=70)
  {
  me->set("title",HIW + "箭狂人" + NOR);
  }
  if(fun>=71)
  {
  me->set("title",HIC + "【" + HIR + "勁弓箭霸" + HIC + "】" + NOR);
  }   */
if(fun>=71)
{
message_vision (  HIC + "$N施展" + HIW + "『" + HIR + "道遠流虛" + HIW + "』" + HIC + "，自在駕馭心箭，變化萬千。\n" + NOR, me);
      me->add("force",-150);
      me->set_temp ("sort1", 1);
      me->set_temp ("flyarrow", 1);
      me->add_temp ("apply/dodge",  60);
      me->add_temp ("apply/attack", 60);
      me->start_call_out((: call_other, __FILE__, "remove_effect", me :), fun+20);
} else if(fun>=36&&fun<=70)
{
message_vision (  HIC + "$N施展" + HIW + "『" + HIR + "法空靈岸" + HIW + "』" + HIC + "，頓時飛沙走石，陣陣漩風迎領而上。 \n" + NOR, me);
      me->add("force",-150);
      me->set_temp ("sort1", 2);
      me->set_temp ("flyarrow", 1);
      me->add_temp ("apply/dodge",  40);
      me->add_temp ("apply/attack", 40);
      me->start_call_out((: call_other, __FILE__, "remove_effect", me :), fun+20);
} else 
{
message_vision (  HIC + "$N施展" + HIW + "『" + HIR + "輕湮飛漫" + HIW + "』" + HIC + "，四周散起陣陣白煙，籠罩著$N。\n" + NOR, me);
      me->add("force",-150);
      me->set_temp ("sort1", 3);
      me->set_temp ("flyarrow", 1);
      me->add_temp ("apply/dodge",  20);
      me->add_temp ("apply/attack", 20);
      me->start_call_out((: call_other, __FILE__, "remove_effect", me :), fun+20);
}
return 1;
}

void remove_effect (object me)
{
  fun=me->query("functions/flyarrow/level");
  if (me->query_temp ("sort1")==1)
  {
  me->add_temp ("apply/dodge",  -60);
  me->add_temp ("apply/attack", -60);
  }
else if (me->query_temp ("sort1")==2)
  {
  me->add_temp ("apply/dodge",  -40);
  me->add_temp ("apply/attack", -40);
  }
else
  {
  me->add_temp ("apply/dodge",  -20);
  me->add_temp ("apply/attack", -20);
  }
  me->delete_temp("flyarrow");
  tell_object (me, HIW + "你感到氣勁緩緩消散了。\n" + NOR);
  if(fun < 100)
  function_improved ("flyarrow",random(500));
}

