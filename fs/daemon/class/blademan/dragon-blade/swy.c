//排版與修改敘述錯誤 並補上一個report_status(enemy[i],1) by blazakira 2011/9/4

#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;

void create() { seteuid(getuid()); }

int again(object me);

int perform( object me, object target )
{
  object weapon, mob, *enemy;
  int i;
  enemy=me->query_enemy();
  i=sizeof(enemy);
/*
  if( me->query_skill( "fast-blade", 1 ) < 90 )
    return notify_fail( "你的幔羅千葉刀法根基不夠, 沒辦法使出無影狂刀斬。\n" );
  if( me->query_skill_mapped("blade") != "fast-blade" )
    return notify_fail( "只有在使幔羅千葉刀法時才能使出無影狂刀斬。\n" );
  if( me->query("family/family_name") != "金刀門" )
    return notify_fail( "只有金刀門徒能用唷。\n" );
  if( !(weapon = me->query_temp("weapon"))||weapon->query("skill_type") != "blade" )
    return notify_fail( "沒有刀是使不出無影狂刀斬的。\n" );
  if( me->query("force") < 300 )
    return notify_fail( "你的內力不夠, 使不出無影狂刀斬。\n" );
*/
  if(userp(me)&&me->query("id")!="swy")
    return notify_fail("只有 npc 和 swy 可用\n");
  if( !me->is_fighting() )
    return notify_fail( "你想用無影狂刀斬砍誰?\n" );
  if( me->query_temp("fast-dest")==1 )
    return notify_fail( "你正在使用。\n" );
  message_vision( HIW + "只見$N手中的刀越舞越快, 身法隨著刀法極速加快,\n"
    "身影也愈來愈糢糊, $N身旁的人已無法看清楚$N的位置,\n" 
    "$N忽然大喝一聲," + HIY + "「～～春風快意流～～」\n" + HIW + "接著開始連續招式攻擊各個敵人。\n" + NOR, me );
  me->add( "force", -300 );
  while(i--) {
    if(enemy[i])
      enemy[i]->start_busy(1);
  }
  me->set_temp( "fast-dest", 1 );
  me->start_busy(1);
  call_out("again", 2, me); 
  return 1;
}

int again(object me)
{
  object *enemy;
  int i,a,fun,gin,kee,sen;
  if(!me) return 1;
  enemy=me->query_enemy();
  i=sizeof(enemy);
  fun=me->query("functions/power-dest/level");
  a=(int)(fun/10)+3;
  if(!me->query_temp("a")) {
    me->set_temp("a",a+1); }
  if(me->query_temp("fast-times")==me->query_temp("a")) {
    tell_object(me,sprintf(HIC + "你的春風快意流施展完了。\n" + NOR));
    me->delete_temp("fast-dest");
    me->delete_temp("a");
    me->delete_temp("fast-times");
    if(fun<100) function_improved("power-dest",random(500));
    return 1;
  }
  while(i--) {
    if(!me||!enemy[i]) continue;
    message_vision(sprintf(HIR + "
突然$N眼露紅光向天怒吼，狂暴運起元功\，使出魔刀失傳之奧義" + HIW + "『盧山不動一劍痕』" + NOR),me,enemy[i]);
    message_vision(sprintf(HIB + "
$N揮著刀刃，順著四季的運轉，向$n砍出『春雨』『夏夜』『秋風』『冬雪』\n" + HIY + "$n被這股狂霸刀氣震嚇住，一瞬間$n身上已留下深及見骨的四道傷痕\n" + NOR),me,enemy[i]);
    kee = enemy[i]->query("max_kee")/35;
    if(kee < 250) kee=250;
    if(kee > 500) kee=500;
    enemy[i]->receive_wound("kee",kee,me);
    COMBAT_D->report_status(enemy[i],1);
    message_vision(HIW + "\n"+
"$N突然領悟五式合一，把『狂龍怒斬』運行到最高境界。\n" + NOR,me,enemy[i]);
    message_vision(HIW + "$N聚精會神，運起狂龍刀法的奧義『" + HIR + "狂龍怒斬～狂" + HIW + "』
$N把所聚狂氣釋放，瞬時一條狂龍飛舞奔向$n。\n" + NOR,me,enemy[i]);
    message_vision(HIW + "$N聚精會神，運起狂龍刀法的奧義『" + HIG + "狂龍怒斬～龍" + HIW + "』
$N把所聚龍氣釋放，瞬時龍鬥氣破空飛斬向$n。\n" + NOR,me,enemy[i]);
    message_vision(HIW + "$N聚精會神，運起狂龍刀法的奧義『" + HIY + "狂龍怒斬～怒" + HIW + "』
$N把所聚怒氣釋放，瞬時怒氣變成怨氣飛向$n。\n" + NOR,me,enemy[i]);
    message_vision(HIW + "$N聚精會神，運起狂龍刀法的奧義『" + HIB + "狂龍怒斬～斬" + HIW + "』
$N把所聚集氣釋放，瞬時刀勁形成刀網撲向$n。\n" + NOR,me,enemy[i]);
    message_vision(HIW + "$N聚精會神，運起狂龍刀法的最高奧義『" + HIC + "狂～龍～怒～斬" + HIW + "』
$N把所有氣同時釋放，瞬時一股強勢的刀勁已妖斬$n。\n" + NOR,me,enemy[i]);
    message_vision(HIR + "$n閃躲不及，被$N的春風快意流五式合一砍了五個大傷口，血流如注。\n" + NOR, me, enemy[i]);
    kee = enemy[i]->query("max_kee")/35;
    if(kee < 250) kee=250;
    if(kee > 500) kee=500;
    enemy[i]->receive_wound("kee",kee,me);
    enemy[i]->start_busy(1);
    COMBAT_D->report_status(enemy[i],1);
  }
  me->add_temp("fast-times",1);
  me->start_busy(1);
  call_out("again", 2, me);
  return 1;
}
