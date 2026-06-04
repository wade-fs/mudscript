// 將dremagic的經驗增加補上一個限制條件 以及更改顏色為ansi的表達方式 by blazakira 2010/9/30
// 由於洛書河圖為超過lv100上限 所以刪除dremagic lv限制 by blazakira
#include <ansi.h>
inherit F_SPELL;
inherit SSERVER;
int fun;
int conjure(object me, object target)
{
  string msg;
  int k;
  fun=me->query("spells/confuse/level");
  if ( fun<=35 ) { k=1; }
  if ( fun>=36&&fun<=70 ) { k=2; }
  if ( fun>=71) { k=3; }
  if ( !me->query("spells/confuse/level")) { return 0; }
  if ( !target ) { target = offensive_target(me); }

  if ( !target ) { return notify_fail("你找不到敵人!!\n"); }
  if ( !me->is_fighting(target) )
    { return notify_fail("夢幻之舞唯在戰鬥中才能使用。\n"); }

  if ( target->is_busy() )
    { return notify_fail("你的法術正迷幻著敵人，繼續攻擊吧!\n"); }

  if ( me->query("family/family_name")!="夜夢小築" )
    { return notify_fail("只有舞者才能使用。\n"); }
  if ( (int)me->query("atman") < 75 )
    { return notify_fail("你的法力不夠﹗\n"); }
  if ( (int)me->query("gin") < 30 )
    { return notify_fail("你的精神沒有辦法有效集中﹗\n"); }

  me->add("atman", -70);
  me->receive_damage("gin", 10);

  write (HIG + "\n                       妳忽然領悟了夜夢天舞中夢幻之舞的絕學。\n" + NOR);
  msg  = HIC + "\n                     $N忽然翩然起舞，眼前只見那美麗的身影幻化出" + NOR;
  msg += HIC + "\n                     無數美妙的舞步，$N舉手投足間令人看得如癡如" + NOR;
  msg += HIC + "\n                         醉，好似天仙下凡，猶如身處幻夢之中。\n\n" + NOR;
  message_vision(msg, me, target);

  if( 80>random(100) ) {
    write (HIG + "\n                             結果成功\的施展出夢幻之舞。\n" + NOR);
    say (HIM + "                     "+target->query("name")+"露出如癡如醉的表情，整個人像失了魂似的!!\n" + NOR,me);
    target->start_busy(k);
//    if ( me->query_skill("dremagic",1) < 100 ) {
    me->improve_skill("dremagic", 1); //}
  } else {
  write (HIR + "\n                           結果絲毫起不了作用令妳暗自惋昔。\n" + NOR);
  say (HIG + "                             但是"+target->query("name")+"絲毫不為所動。\n" + NOR,me);
  }

  if ( fun < 100 )
    { me->spell_improved("confuse",random(1000)); }
  COMBAT_D->report_status(target);
  return 1;
}

