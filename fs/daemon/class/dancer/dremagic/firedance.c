//增加使用者存在與否（離線？）的判定 與調整顏色為ansi碼 跟 補上receive_damage 的攻擊方參數 by blazakira 2011/5/4

#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;

int conjure(object me, object target)
{
  string msg;
  fun=me->query("spells/firedance/level");
  if (!me->query("spells/firedance/level"))
    return 0;

  if( !target ) target = offensive_target(me);
  if(!target) return notify_fail("你找不到敵人!!\n");
  if(!me->is_fighting(target) ) return notify_fail("這法術只能對戰鬥中的對手使用。\n");

  if(me->query("family/family_name")!="夜夢小築")
    return notify_fail("只有舞者才能使用。\n");
  if((int)me->query("atman") < 150)
    return notify_fail("你的法力不夠﹗\n");
  if(me->query_temp("firedance")==1) 
    return notify_fail("你剛施過法術, 正等待精神集中!!\n"); // 加入判斷式避免連放
  if((int)me->query("gin") < 10 )
    return notify_fail("你的精神沒有辦法有效集中﹗\n");

  me->add("atman", -150);
  me->receive_damage("gin", 10, me);

  write( HIG"\n            妳領悟了夜夢天舞及夢玄法鑑的精髓，預備施展"HIR"火鳳飛翔"HIG"之術。\n"NOR);
  msg = HIC "\n                   $N的身體漸漸的被火燄包圍，而$N的身形也漸" NOR;
  msg += HIY "\n                     漸的幻化為一隻鳳凰，只見一隻火鳳凰迅速的" NOR;
  msg += HIG "\n                       向著$n飛去，令$n不及招架。\n\n" NOR;
  message_vision(msg, me, target);
  if( 80 > random(100) ) {
    write( HIG"\n                     結果成功\的施展出火鳳飛翔。\n"NOR);
    say( HIR"                     "+target->query("name")+HIR+"閃躲不及，渾身上下都著了火，痛苦異常!!\n"NOR);
    target->receive_damage("kee",(fun*9+250),me);
    target->apply_condition("burn",random(15) +fun/10);
    if ( fun < 100)
      me->spell_improved("firedance",random(700));
  } else {
    write(HIR"\n                     結果絲毫起不了作用令妳暗自惋昔。 \n"NOR);
    say( HIG"               只見"+target->query("name")+HIG+"以迅雷不及掩耳之速閃過攻擊。\n"NOR);
    if (fun < 100)
    me->spell_improved("firedance",random(700));
  }

  COMBAT_D->report_status(target);
  me->set_temp("firedance",1);
  call_out("ready",2,me);
// me->start_busy(1);  dancer 法術傷害已跟不上mob的發展 故取消之 unfinished 2004/2/6
  return 1;
}

int ready(object me) 
{
  if(me) {
    me->delete_temp("firedance");
    return 1;
  }
}
