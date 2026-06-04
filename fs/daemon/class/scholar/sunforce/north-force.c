/*
改版構想
第一版只以吸取內力為主，在看過笑傲江湖後，發現被吸者會全身無力，所以
在第二版將改成等級越高能吸的東西越多(精氣神，內力)
                                                by bss
*/
#include <combat.h>
#include <ansi.h>
#define VERSION "第二版"
inherit SSERVER;
inherit F_FUNCTION;
int NorthForceSpPerform (object me, int fun);
int perform(object me, object target)
{
  object *enemy,ob;
  int damage,i,fun,accept,e_force,e_f_c,flag;
  int e_kee,have_get_kee;
  flag=0;
  have_get_kee = 0;
  if (!me->query("marks/north-force")) {
    return 0;
  }
  fun = me->query("functions/north-force/level");
  if (me->query_skill("sunforce",1)< 100)
    return notify_fail("你的一陽心法根基不夠﹐"+
                        "沒辦法使出北冥神功\。\n");
  if (me->query("family/family_name") != "段家")
    return notify_fail("非段家弟子不能用！！\n");
  if (!me->is_fighting()) {
    if (me->query("marks/north-force") > 1 && fun >= 100) {
      return NorthForceSpPerform (me, fun);
    }
    else {
      return notify_fail("北冥神功\只能在戰鬥中使用。\n");
    }
  }
  if (me->query("kee") < 1000 && fun <= 80 )
    return notify_fail("你的氣不夠。\n");

  enemy=me->query_enemy();
  i=sizeof(enemy);
  if (i > 4) {
    i = 4;
  }

  message_vision(HIG + "
                $N運起全身真勁，使得全身的骨骼不斷的霹啪作響，
                大喝一聲:"+BLINK+HIC+"「北冥神功\」" + NOR+HIG + "，右手開始不斷的在身前繞
                圈，越繞越快，漸漸地形成了一個漩渦力場，四週的
                人只覺得一股極大的吸力從力場中心發出，身體不由
                自主的朝力場投去。\n" + NOR,me);
  while (i--) {
    if (fun <= 20 && fun >=0) {
      if (30 > random(100) || enemy[i]->is_busy()){
        e_force=enemy[i]->query("force");
        if (e_force > 10) {
          message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的一成!!!\n" + NOR,enemy[i],me);
          flag = flag + 1;
          e_force=e_force*1/10;
          enemy[i]->add("force",-(e_force));
          me->add("force",e_force);
        }
        e_f_c=enemy[i]->query("force_factor");
        if(4 > random(100) && e_f_c >= 5) {
          e_f_c=e_f_c*2/10;
          enemy[i]->add("force_factor",-(e_f_c));
        }
      }
      else {
        message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
      }
    }
    else if (fun <= 40 && fun >20) {
      if (45 > random(100) || enemy[i]->is_busy()) {
        e_force=enemy[i]->query("force");
        if (e_force > 10) {
          message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的兩成!!!\n" + NOR,enemy[i],me);
          flag = flag + 1;
          e_force=e_force*2/10;
          enemy[i]->add("force",-(e_force));
          me->add("force",e_force);
        }
        e_f_c=enemy[i]->query("force_factor");
        if (6 > random(100) && e_f_c >= 4) {
          e_f_c=e_f_c*3/10;
          enemy[i]->add("force_factor",-(e_f_c));
        }
      }
      else {
        message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
      }
    }
    else if (fun <= 60 && fun >40) {
      if (60 > random(100) || enemy[i]->is_busy()) {
        e_force=enemy[i]->query("force");
        if (e_force > 10) {
          message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的三成!!!\n" + NOR,enemy[i],me);
          flag=flag+1;
          e_force=e_force*3/10;
          enemy[i]->add("force",-(e_force));
          me->add("force",e_force);
        }
        e_f_c=enemy[i]->query("force_factor");
        if (8 > random(100) && e_f_c >= 3) {
          e_f_c=enemy[i]->query("force_factor");
          e_f_c=e_f_c*4/10;
          enemy[i]->add("force_factor",-(e_f_c));
        }
      }
      else {
        message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
      }
    }
    else if (fun <= 80 && fun >60) {
      if (75 > random(100) || enemy[i]->is_busy()) {
        e_force=enemy[i]->query("force");
        if (e_force > 10) {
          message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的四成!!!\n" + NOR,enemy[i],me);
          flag=flag+1;
          e_force=e_force*4/10;
          enemy[i]->add("force",-(e_force));
          me->add("force",e_force);
        }
        e_f_c=enemy[i]->query("force_factor");
        if (10 > random(100) && e_f_c >= 2) {
          e_f_c=e_f_c*5/10;
          enemy[i]->add("force_factor",-(e_f_c));
        }
      }
      else {
        message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
      }
    }
    else if(fun > 80) {
      if(80 > random(100) || enemy[i]-> is_busy()) {
        e_force=enemy[i]->query("force");
        if (e_force > 10) {
          message_vision(HIR + "
$N" + HIR + "一時之間慌了手腳，竟被$n" + HIR + "吸走了自身內力中的五成!!!\n" + NOR,enemy[i],me);
          flag=flag+1;
          e_force=e_force*5/10;
          enemy[i]->add("force",-(e_force));
          me->add("force",e_force);
        }
        e_f_c=enemy[i]->query("force_factor");
        if (12 > random(100) && e_f_c >= 2) {
          e_f_c=e_f_c*6/10;
          enemy[i]->add("force_factor",-(e_f_c));
        }
        if (fun >= 100 && (50 + (fun - 100)) > random (100)) {
          e_kee = enemy[i]->query("kee");
          e_kee = e_kee*1/10;
          if (e_kee < 100) {
            e_kee = 100;
          }
          message_vision(HIR + "
$n" + HIR + "吸完$N" + HIR + "的內力之後卻不放手，深吸了一口氣，$N" + HIR + "又被$n" + HIR + "吸走了一成的氣!!!\n" + NOR,enemy[i],me);
          enemy[i]->receive_wound("kee",e_kee,me);
          enemy[i]->receive_damage("kee",e_kee,me);
          COMBAT_D->report_status(enemy[i]);
          me->receive_curing("kee",e_kee);
          me->receive_heal("kee",e_kee);
          COMBAT_D->report_status(me);
          have_get_kee = 1;
        }
      }
      else {
        message_vision(HIY + "
$N" + HIY + "看準了$n" + HIY + "所引發力場的破綻，一個閃身，躲開了$n" + HIY + "這次攻擊。\n" + NOR,enemy[i],me);
      }
    }
  }
  if (!have_get_kee && userp (me)) {
    me->add("kee",-random(200));
    message_vision(HIR + "$N" + HIR + "因為使出" + HIC + "「北冥神功\」" + HIR + "中的吸功\法，消耗了部分的氣!!!\n" + NOR,me);
    COMBAT_D->report_status(me);
  }
  if (!flag) flag=1;
  if (fun < 100) {
    me->function_improved("north-force",(random(300) + fun) * flag);
  }
  return 1;
}

/*
北冥神功非戰鬥時期功能
要先解迷
if marks/north-force == 2
  所在的房間如果沒被人吸過天地靈氣的話就可以吸天地靈氣療傷，若無傷勢就可以吸天地靈氣增加內力
else if marks/north-force == 3
  不管所在位子有沒有被吸過都可以療傷或增加內力

療傷期間會扣內力

fun >= 100 && <= 109, 一次回復最大值的一成, 等待時間四秒, force-=1000
fun >= 110 && <= 119, 一次回復最大值的二成, 等待時間五秒, force-=900
fun >= 120 && <= 129, 一次回復最大值的三成, 等待時間六秒, force-=800
fun >= 130 && <= 139, 一次回復最大值的四成, 等待時間七秒, force-=700
fun >= 140 && <= 149, 一次回復最大值的五成, 等待時間八秒, force-=600
fun == 150, 一次回復最大值的六成, 等待時間三秒, force-=500

*/
int GetRecoverValue (int MaxValue, int fun)
{
  switch (fun) {
    case 100..109:
      return MaxValue*1/10;
    case 110..119:
      return MaxValue*2/10;
    case 120..129:
      return MaxValue*3/10;
    case 130..139:
      return MaxValue*4/10;
    case 140..149:
      return MaxValue*5/10;
    case 150:
      return MaxValue*6/10;
    default:
      return 0;
  }
}
void NorthForceSpPerformEnd (object me, int fun)
{
  mapping my;
  int HaveSecure, force;
  
  if (!me) return ;
  if (!me->query_temp("NorthForceInUse")) return;
  me->delete_temp("NorthForceInUse");
  if (me->query("ghost")) return ;
  if (me->is_fighting()) return ;
  my = me->query_entire_dbase();
  HaveSecure = 0;

  if (my["eff_gin"] < my["max_gin"]) {
    me->receive_curing("gin", GetRecoverValue (my["max_gin"], fun));
    HaveSecure = 1;
  }
  if (my["eff_kee"] < my["max_kee"]) {
    me->receive_curing("kee", GetRecoverValue (my["max_kee"], fun));
    HaveSecure = 1;
  }
  if (my["eff_sen"] < my["max_sen"]) {
    me->receive_curing("sen", GetRecoverValue (my["max_sen"], fun));
    HaveSecure = 1;
  }
  if (my["gin"] < my["max_gin"]) {
    me->receive_heal("gin", GetRecoverValue (my["max_gin"], fun));
    HaveSecure = 1;
  }
  if (my["kee"] < my["max_kee"]) {
    me->receive_heal("kee", GetRecoverValue (my["max_kee"], fun));
    HaveSecure = 1;
  }
  if (my["sen"] < my["max_sen"]) {
    me->receive_heal("sen", GetRecoverValue (my["max_sen"], fun));
    HaveSecure = 1;
  }
  if (me->query("marks/north-force") > 3 && me->query_condition()) {
    me->clear_condition ();
    me->clear_condition ("mogi");
    me->clear_condition ("lyssa");
    HaveSecure = 1;
  }
  if (!HaveSecure) {
    force = GetRecoverValue (my["max_force"], fun);
    if ((my["force"] + force) > (my["max_force"] * 2)) {
      my["force"] = (my["max_force"] * 2);
    }
    else {
      my["force"] += force;
    }
    message_vision(HIY + "
                $N張開雙眼，成功\的轉換天地靈氣成為內力\n" + NOR,me);
  }
  else {
    message_vision(HIY + "
                $N張開雙眼，成功\的利用天地靈氣治療了身體的損傷\n" + NOR,me);
    COMBAT_D->report_kee (me);
    COMBAT_D->report_status (me);
  }
  if (fun < 150) {
    me->function_improved("north-force",(random(300) + fun));
  }
  return ;
}

int NorthForceSpPerform (object me, int fun)
{
  mapping my;
  int delay;

  if (!me) return 0;
  if (me->query("ghost")) return 0;
  my = me->query_entire_dbase();

  if (me->query_temp("NorthForceInUse")) {
    return notify_fail ("你正在吸天地靈氣。\n");
  }
  if (my["eff_gin"] >= my["max_gin"] &&
      my["eff_kee"] >= my["max_kee"] &&
      my["eff_sen"] >= my["max_sen"] &&
      my["gin"] >= my["max_gin"] &&
      my["kee"] >= my["max_kee"] &&
      my["sen"] >= my["max_sen"] &&
      my["force"] >= (my["max_force"] * 2)) {
    return notify_fail ("你的狀況良好，再吸也吸不到甚麼了\n");
  }
  if (my["force"] < (500 + ((((150 - fun) / 10) + 1) * 100))) {
    return notify_fail ("你的內力不足\n");
  }
  if (environment(me)->query("HaveUseNorthForce") && me->query("marks/north-force") == 2) {
    return notify_fail ("你沒辦法從這裡吸到任何的天地靈氣。\n");
  }
  environment(me)->set("HaveUseNorthForce", 1);

  switch (fun) {
    case 100..109:
      delay = 4;
      break;
    case 110..119:
      delay = 5;
      break;
    case 120..129:
      delay = 6;
      break;
    case 130..139:
      delay = 7;
      break;
    case 140..149:
      delay = 8;
      break;
    case 150:
      delay = 3;
      break;
    default:
      delay = 10;
      break;
  }
  message_vision(HIY + "
                $N盤膝坐下，闔上雙眼，利用北冥神功\開始吸取天地靈氣\n" + NOR,me);
  my["force"]-= ((((150 - fun) / 10) + 1) * 100);
  me->set_temp("NorthForceInUse",1);
  me->start_call_out( (: call_other, __FILE__, "NorthForceSpPerformEnd", me, fun:), delay);
  return 1;
}

