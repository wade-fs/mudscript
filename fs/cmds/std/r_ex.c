// version.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
  int  force;
  string ena_force;
  seteuid(getuid());
  force = me->query_skill("force", 1) /2; 

  if(me->is_fighting()) notify_fail("戰鬥中練什麼功\好好的打對手吧。\n");
  if(me->query_condition("ff_poison"))
    return notify_fail("你氣血失調﹐無法運氣。\n");
  if(me->query_temp("saving_die"))
    return notify_fail("你正在救人, 沒有辦法運氣!!!\n");

  if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
    return notify_fail("你現在精神狀況太差了﹐無法凝神專一﹗\n");

  if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
    return notify_fail("你現在精力不夠﹐無法控制內息的流動﹗\n");
  if(me->is_busy()) notify_fail("你正在忙碌中！\n");
  if(force < 10) return notify_fail("您的基本內力功\力不足，無法練氣。\n");
  if (me->query_condition("no_power_e"))
    return notify_fail (HIM"你感覺到體內有無數的氣勁亂流, 使你無法正常的使用內力。\n"NOR);
  if (me->query_temp("crazy"))
    return notify_fail (HIR"你正陷入狂暴狀態, 無法控制內息流動。\n"NOR);
  if ((me->query("food")<1 || me->query("water")<1) && userp(me)) {
    if (random(100) < 1) {
      me->receive_wound ("kee", me->query("age"));
      return notify_fail( RED"你感覺又餓又渴, 一時之間無法控制真氣, 受到了內傷!"NOR );
    }
    return notify_fail( BLU"你感覺又餓又渴! 無法運氣!\n"NOR );
  }
        ena_force = me->query_skill_mapped("force");
        if( !stringp(ena_force) )
                return notify_fail("你必須先用 enable 選擇你要用的內功\心法。\n");


  if(me->query_condition("force") > 0) return notify_fail("您現在已經開始練氣了。\n");
  if(me->query_condition("dhyana") > 0) return notify_fail("您現在已經開始參悟佛法了。\n");

  me->apply_condition("force",force);
  message_vision(
                HIW "$N開始盤腿坐下，嘗試著集中精神提昇基本內功\能力。\n"NOR,me);

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : r_ex
 
使用這個指令會開始練氣。
 
HELP
    );
    return 1;
}
 
