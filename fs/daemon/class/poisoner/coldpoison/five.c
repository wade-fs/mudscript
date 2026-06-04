//修正對象不存在的錯誤訊息 並補上receive_damage施展者的判定 by blazakira 2011/4/9

#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;

int perform(object me, object target)
{
  string msg;
  object ob;
  if(me->is_fighting()) {
    target = offensive_target(me);
  } else {
    if(!target) return notify_fail("你要打誰？\n");
  }
  if(target==me) return notify_fail("攻擊自己???找死嗎?\n");
  if(!(ob=present("five poison",me)))
    return notify_fail("你的身上沒有五毒。\n");
  if( environment(me)->query("no_fight") )
    return notify_fail("這裡不准戰鬥。\n");
//  if(target->query_temp("five-1")==1)
  if(target && living(target) && target->query_temp("five-1")==1) //增加對象存在與否的判定 by blazakira
    return notify_fail("對特定人物只能用一次。\n");
  if(me->query("family/family_name")!="冥蠱魔教")
    return notify_fail("你不是魔教徒。\n");
  if(me->query_temp("is_five"))
    return notify_fail("你正在使用。\n");
  msg=HIC + "$N吸納五毒，聚精會神伺機而動。\n" + NOR;
  message_vision(msg, me);
  ob->add_amount(-1);
  me->set_temp("is_five",1);
  call_out("act1",3,msg,target,me);
  return 1;
}

int act1(string msg,object target,object me) {
  if(!me) return 1;
  fun=me->query("functions/five/level");
  me->delete_temp("is_five");
  if(!target) return notify_fail("可能是精神錯亂的緣故,你發現你竟然找不到敵人!!\n");
  if(environment(me)!=environment(target))
    return notify_fail("敵人不在這。\n"); 
  if(!target) return notify_fail("敵人不見了。\n");
  if(!living(target)) return notify_fail("敵人已死了。\n"); 
  if(80>random(100))
  {
    msg=HIR + "$N見機「碰」的一聲，$n身上已留下一個黑掌印。\n" + NOR;
    target->apply_condition("five_poison",5);
    target->receive_damage("kee",me->query("functions/five/level"),me);
    target->set("five",me->query("functions/five/level")*10);   
    if(target->query_temp("poison/five_poison"))
      target->set_temp("poison/five_poison",target->query_temp("poison/five_poison") - ({ me }) - ({ 0 }) + ({ me }) );
    else
      target->set_temp("poison/five_poison",({ me }));

    if(target->query("id")=="degu sa") target->set_temp("five-1",1); //替獨孤嵊(degu sa)加上保護
    target->kill_ob(me);
    me->kill_ob(target);
  } else msg= HIG + "$N見機「碰」的一聲，$n見情勢危急，急防躲開。\n" + NOR;
  message_vision(msg, me, target);
  if(fun<100) function_improved("five",random(700));
  return 1;
}
