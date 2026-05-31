// cmds acus for doctor by nike - 9/16/2001 -
//修正因為開放cure上限而造成無法修煉的問題 by blazakira 2014/1/22

#include <ansi.h>
inherit F_FUNCTION;
inherit F_GUILDCMDS;

void do_acus(object me);
int abate(int r_time,object me);
int acus_fail(object me);

int main(object me,string arg)
{
  int time, lv;
  object weapon;

  if(!me) return 1;
  if(me->query("doctor/acus") && !wizardp(me)) return 0;
  if(me->query("family/family_name")!="銀針門" && !wizardp(me))
    return notify_fail("你不是醫生，怎麼可能會使玄元針灸術？\n");
  if((int)me->query_skill("cure", 1) <= 90)
    return notify_fail("你的醫術太低，無法使出玄元針灸術！\n");
  if((int)me->query("combat_exp") < 1500000)
    return notify_fail("你的經驗值太低，無法使出玄元針灸術！\n");
  if((int)me->query("functions/break-kee/level") < 60)
    return notify_fail("你的「破穴指」太低了，無法使出玄元針灸術！\n");
  if((int)me->query("functions/gold-needle/level") < 60)
    return notify_fail("你的「金針封穴」太低了，無法使出玄元針灸術！\n");
  if(me->query_temp("mpower") == 1)
    return notify_fail("你已經把自己扎的跟刺蝟一樣了，還想扎ㄚ？\n");
  weapon=me->query_temp("weapon");
  if(!weapon)
    return notify_fail("你手中無針，要拿啥來使玄元針灸術？\n");
  if(weapon->query("skill_type") != "stabber")
    return notify_fail("你手中無針，要拿啥來使玄元針灸術？\n");
//安全數，定高一點
  if((int)me->query("gin") < 500
    || (int)me->query("kee") < 500
    || (int)me->query("sen") < 500
    || (int)me->query("force") < 500)
    return notify_fail("喂！再多扎個幾針你的身體就快負荷不了唷！\n");

  message_vision(HIC"$N拿起手中的針，施展"HBBLU+HIR"--="HIY"玄元針灸術"HIR"=--"NOR+HIC"，對準自己的穴道扎了進去...\n\n"NOR,me);
  message_vision(HIG"$N瞬間感到能力倍增，似乎體內有股源源不斷的能量正欲爆發而出！！！\n\n"NOR,me);
  //me->start_call_out((:call_other, __FILE__, "do_acus", me:), lv);
  lv = (int)me->query("functions/acus/level");
  if(lv > 30)
    time= 30 + random(10);
  else
    time = lv + random(10);
  lv = (int)me->query("functions/acus/level")*4;
  //call_out("abate", time, me);
  me->set_temp("mpower",1);
  if(me->is_fighting())
    me->start_busy(1);
  if(lv<time)
    call_out("do_acus",lv,me);
  else {
    lv=lv-time;
    call_out("abate",time,lv,me);
  }
  return 1;
}

void do_acus(object me)
{
  int lv;

  if(!me) return ;
  lv = (int)me->query("functions/acus/level");
  message_vision(HIB"$N對自己的所施展的玄元針灸術慢慢的失效了...\n"NOR,me);
  me->delete_temp("mpower");
  if( lv < 100) function_improved("acus",random(lv) * 5 +50);
  return ;
}

/*  不必要..先mark起來 by obs
int acus_fail(object me)
{
  if(!me) return 1;   
  message_vision(HIB"$N對自己的所施展的玄元針灸術慢慢的失效了...\n"NOR,me);
  me->delete_temp("mpower");
  return 1;
}
*/

int abate(int r_time,object me)
{
  int lv, time, sub, damage;

  if(!me) return 1;
  lv=(int)me->query("functions/acus/level");
  if(me->is_fighting())
    damage=700+random(100);
  else
    damage=500+random(100);
  sub = (int)me->query_skill("cure",1)*3;
//增加判斷 by blazakira
  if(sub<0)
    sub=0;
  else if(sub>120*3)
    sub=120*3;

  sub=damage-sub;
  lv = (int)me->query("functions/acus/level");
  time = (int)me->query("functions/acus/level");
  time = time + 10 + random(5);
  if(time > 30)
    time = 30;
  //if(!me->query_temp("mpower")) return 1;
//把yu-needle裡有個加強攻擊的temp設在這裡觸發
  if(lv >=50 && !me->query_temp("crazy_hit") && 30 > random(100))
    me->set_temp("crazy_hit");
// 以下//mark掉的判斷..為預防重複運以及顯示錯誤  by obs
// 加入gin kee sen force消耗判斷..避免低於0而無故死亡  by obs
  if(lv <= 25)
  {
//    if((me->query("gin")-sub) < 500) return acus_fail(me);
    message_vision(HIR"$N針灸的傷口突然隱隱作痛，$N的精力減少了...\n" NOR, me);
    if(me->query("gin") > 0 && !me->query_temp("unconcious"))
      me->receive_damage("gin", sub);
    if(r_time<time)
      call_out("do_acus",r_time,me);
    else {
      r_time=r_time-time;
      call_out("abate", time, r_time, me);
    }
    return 1;
  }
  sub = (int)me->query_skill("cure",1)*2;
//增加判斷 by blazakira
  if(sub<0)
    sub=0;
  else if(sub>120*2)
    sub=120*2;

  sub=damage-sub;
  if(lv >= 26 && lv <= 50)
  {
//    if((me->query("kee")-sub) < 500) return acus_fail(me);
    message_vision(HIR"$N針灸的傷口突然隱隱作痛，$N的氣血減少了...\n" NOR, me);
    if(me->query("kee") > 0 && !me->query_temp("unconcious"))
      me->receive_damage("kee", sub);
    if(r_time<time)
      call_out("do_acus",r_time,me);
    else {
      r_time=r_time-time;
      call_out("abate", time, r_time, me);
    }
    return 1;
  }
  sub = (int)me->query_skill("cure",1);
//增加判斷 by blazakira
  if(sub<0)
    sub=0;
  else if(sub>120)
    sub=120;

  sub=damage-sub;
  if(lv >= 51 && lv <= 75)
  {
//    if((me->query("sen")-sub) < 500) return acus_fail(me);
    message_vision(HIR"$N針灸的傷口突然隱隱作痛，$N的神瞑減少了...\n" NOR, me);
    if(me->query("sen") > 0 && !me->query_temp("unconcious"))
      me->receive_damage("sen", sub);
    if(r_time<time)
      call_out("do_acus",r_time,me);
    else {
      r_time=r_time-time;
      call_out("abate", time, r_time, me);
    }
    return 1;
  }
  sub = (int)me->query_skill("cure",1)/2;
  if(sub<0)
    sub=0;
  else if(sub>120/2)
    sub=120/2;
  sub=damage-sub;
  if(lv >= 76)
  {
//    if((me->query("force")-sub) < 500) return acus_fail(me);
    message_vision(HIR"$N針灸的傷口突然隱隱作痛，$N的內力減少了...\n" NOR, me);
    if(me->query("force") > 0)
      me->add("force", -sub);
    if(r_time<time)
      call_out("do_acus",r_time,me);
    else {
      r_time=r_time-time;
      call_out("abate", time, r_time, me);
    }
    return 1;
  }
  return 1;
}

