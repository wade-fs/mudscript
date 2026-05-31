//瓢陽指勁的專用武器......
//更改使用者的判定為user = this_player()>>user = environment(this_object()) by blazakira 2011/4/17
//改變wield與unwield形式為int wield() (參考殺意魔戒) 且區分狀態表達(report_status)為eff_kee or kee by blazakira 2011/8/8
//取消內力大於兩萬就一次清空內力的判定 並改為 每次出招 不論成功與否就扣內力6000作為取代 by blazakira 2013/3/1

#include <weapon.h>
#include <ansi.h>
inherit STABBER;

int lv_check(object ob);
int do_shoot();
object user;

void create()
{
  set_name(HBMAG+HIC"飄"HIR"陽"HIW"扇"NOR, ({"finger fan", "fan"}) );
  set_weight(10000);
  set("no_sell",1);
  set("no_auc",1);
  set("no_drop",1);
  set("no_put",1);
  set("no_give",1);
  set("no_sac",1);
  set("no_steal",1);
  set("finger-fan",1);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "柄");
    set("long","
由前代武器大師北勝天所構思，由一種可以百分之百傳遞內勁的奇異金屬所製成，
是北勝天為段家所做的終極兵器，可以在戰鬥中射出(shoot)事前鍊化入飄陽扇的
一陽指氣傷害敵人。
cf 可以查查看fan裡面還存有幾隻氣勁
當飄陽指勁的等級到達90以上時可以set fan_auto_shoot，會自動射出指勁
否則都要用shoot來射。\n");
    set("value", 10000);
    set("material", "crimsonsteel");
    set("wield_msg", HIY"$N將$n"HIY"拿在手上，感覺全身的內勁好像永不停止般流入$n"HIY"中。\n"NOR);
    set("unwield_msg", HIY"$N將$n"HIY"插回$n"HIY"的專用皮套內，忽然有一種失落感。\n"NOR);
  }
  init_stabber(100);
  setup();
}

void init()
{
//  add_action("do_wield","wield");
//  add_action("do_unwield","unwield");
//  add_action("do_drop","drop");
//  add_action("do_auc","auc");
//  add_action("do_give","give");
  add_action("do_shoot","shoot");
  add_action("do_check","cf");
}

int wield()
{
  int result = ::wield();
  if( query("equipped"))
  {
    user = environment(this_object());
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  int ret = ::unequip();
  if( !query("equipped"))
  {
    set_heart_beat(0);
  }
  return ret;
}
/*
int do_wield(string str)
{
  if(!query("equipped") )
  {
    if(!user) user=this_player();
    if(!user) user=previous_object();
    if(user)
    set_heart_beat(1);
  }
}

int do_drop(string str)
{
  if(str=="finger fan" || str=="fan" || str=="all")
    if( query("equipped") )
    {
      set_heart_beat(0);
    }
}

int do_give(string str)
{
  if(str=="finger fan" || str=="fan" || str=="all")
    if( query("equipped") )
    {
      set_heart_beat(0);
    }
}

int do_unwield(string str)
{
  if(str=="finger fan" || str=="fan" || str=="all")
    if( query("equipped") )
    {
      set_heart_beat(0);
    }
}

int do_auc(string str)
{
  if(str=="finger fan" || str=="fan" || str=="all")
    if( query("equipped") )
    {
      set_heart_beat(0);
    }
}
*/
int do_shoot()
{
  object me,*enemy;
  int i,j,fun,damage,k,sk_lv,power,delay;
  me=user;

  if(!me) return notify_fail("無法使用，建議unwield後再wield試試!!\n");

  if(!query("equipped"))
    return 0;

  if(me->is_busy())
    return 0;

  if(!(me->query("family/family_name")=="段家" && me->query("marks/fan-finger") && me->query("marks/six_sp")==3))
  {
    write("你不夠資格使用本扇，我將離你而去!!\n");
    message_vision(HIM"只見一道奇異的紫光由$N"+HIM+"發出，$n定睛一看，卻發現$N"+HIM+"正從$n的手上消失不見!!!\n"NOR,this_object(),me);
    if(query_heart_beat())
      set_heart_beat(0);
    destruct(this_object());
    return 1; //既然刪除物件了就別往下判斷 by blazakira
  }

  if(!me->query_temp("fan-finger"))
    return notify_fail(HIC"你並沒有鍊化一陽指氣到"HIC"飄"HIY"陽"HIW"扇裡!!\n"NOR);

  if(!me->is_fighting())
    return notify_fail(HIY"只有在戰鬥中才可以使用「飄陽指勁」。\n"NOR);

  if(me->query("force") <= 100)
    return notify_fail(HIR"你的內力已經用盡，再沒有內力來發出「飄陽指勁」。\n"NOR);

  if(me->query_temp("finger-rest",1))
    return notify_fail(HIY"你因為使出「飄陽指勁」，使得自身的內息翻滾不定，暫時無法再使出「飄陽指勁」。\n"NOR);

  enemy=me->query_enemy();
  j=sizeof(enemy);
  fun=me->query("functions/fan-finger/level");
  switch (fun) {
    case 0..20:
      damage=fun*(random(7)+1);
      delay = 7;
      break;
    case 21..40:
      damage=fun*(random(7)+2);
      delay = 6;
      break;
    case 41..60:
      damage=fun*(random(7)+3);
      delay = 5;
      break;
    case 61..80:
      damage=fun*(random(7)+4);
      delay = 4;
      break;
    case 81..100:
      damage=fun*(random(7)+5);
      delay = 3;
      break;
    case 101..119:
      damage=fun*(random(7)+6);
      delay = 2;
      break;
    case 120:
      damage=fun*(random(5)+12);
      delay = 1;
      break;
    default:
      damage=fun*random(8);
      delay = 8;
      break;
  }
  if (damage < 100 ) {
    damage=100;
  }

  if(me->query_temp("fan_damage_up")) {
    me->delete_temp("fan_damage_up");
    power=me->query("combat_exp")/2000000+1;
    damage=damage*power;
    me->add("force",-500);
    message_vision(BLINK+HIY"
$N領悟到指勁揮出時角度的重要性，手中的"+NOR+"$n"+BLINK+HIY+"以一個敵人完全無法閃躲的角度揮了出去!!\n"NOR,me,this_object());
  }

  if (damage > 10000 && userp(me)) {
    damage = 10000;
  }

  if(wizardp(me))
    tell_object(me,sprintf("damage=%d\n",damage));
  if(fun > 80 && ( me->query("force") > 600 )) {
    if(fun>=100 && me->query_temp("fan-finger") >= 5 && (10 > random(100) || wizardp(me)) && me->query("force")>2000 && me->query("env/飄陽扇連擊") ) {
      message_vision(HIM"
     $N"HIM"忽然領悟到了"BLINK+HIR"「飄陽指勁」"NOR+HIM"中"BLINK+HIY"「飄渺虛無，真陽縱橫」"NOR+HIM"的真意，口中大喝
     "HBRED+HIY"「飄～陽～指～勁～巧～連～環」"NOR+HIM"，手中$n"HIM"一揚，五道不同顏色的指勁騰空
     而出，如有靈性般的奔向各敵。\n
  "NOR,me,this_object());
      i=random(j);
      if(enemy[i]) {
        if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 20000 ) {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第一次扣
          message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第一式"HBRED+HIY"「沉陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
          enemy[i]->receive_damage("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+1);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第一次扣
          message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
        }
      }
      i=random(j);
      if(enemy[i]) {
        if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 20000 ) {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第二次扣
          message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第二式"HBMAG+HIY"「重陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
          damage=damage+100;
          enemy[i]->receive_damage("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+2);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第二次扣
          message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
        }
      }
      i=random(j);
      if(enemy[i]) {
        if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 20000 ) {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第三次扣
          message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第三式"HBGRN+HIW"「絕陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
          damage=damage+200;
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+3);
          COMBAT_D->report_status(enemy[i],1);
        } 
        else {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第三次扣
          message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
        }
      }
      for(i=0;i<j;i++)
      {
        if(!enemy[i]) continue;
        if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 20000 ) {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第四次扣
          message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第四式"HBYEL+HIC"「玄陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
          damage=damage+300;
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+4);
          COMBAT_D->report_status(enemy[i],1);
        }
        else {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第四次扣
          message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
        }
      }
      for(i=0;i<j;i++)
      {
        if(!enemy[i]) continue;
        if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 20000 )
        {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第五次扣
          message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第五式"BLINK+HIC"「靈陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
          damage=damage+400;
          enemy[i]->receive_wound("kee",damage,me);
          COMBAT_D->report_status(enemy[i],1);
          enemy[i]->receive_damage("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+5);
          COMBAT_D->report_status(enemy[i]);
        }
        else {
          if( me->query("force") > 20000 ) me->add("force",-6000); //第五次扣
          message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
        }
      }
      if(me->query("force") > 20000)
      {
//        me->set("force",100);
        message_vision(HIY"$N因為使出了"BLINK+HIR"「飄陽指勁」"NOR+HIY"的連續招，體內的內息狂洩而出，使得體內的內力所剩無幾了!!!\n"NOR,me);
      }
      else {
        me->add("force",-2000);
        message_vision(HIY"$N因為使出了"BLINK+HIR"「飄陽指勁」"NOR+HIY"的連續招，體內的內息狂洩而出，體內的內力嚴重的流失了!!!\n"NOR,me);
      }
      me->add_temp("fan-finger",-5);
      me->set_temp("finger-rest",1);
      call_out("rest",delay,me);
      return 1;
    }
    message_vision(HIY"
     $N"HIY"將手中$n"HIY"用力一揮，一道氣勁由$n"HIY"呼嘯而出，正是大理段氏另一個
     絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第五式"BLINK+HIC"「靈陽勁」"NOR+HIY"，指勁化繁為簡，如有靈性
     般的奔向各敵。\n
"NOR,me,this_object());

    for(i=0;i<j;i++)
    {
      if(!enemy[i]) continue;
      if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) ) {
        message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
        damage=damage+400;
        enemy[i]->receive_wound("kee",damage,me);
        COMBAT_D->report_status(enemy[i],1);
        enemy[i]->receive_damage("kee",damage,me);
        enemy[i]->apply_condition("bleeding", random(10)+5);
        COMBAT_D->report_status(enemy[i]);
      }
      else {
        message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
      }
    }
    me->add("force",-600);
    me->add_temp("fan-finger",-1);
    me->set_temp("finger-rest",1);
    call_out("rest",delay,me);
    return 1;
  }
  if(fun >60 && ( me->query("force") > 400 )) {
    message_vision(HIY"
     $N"HIY"將手中$n"HIY"用力一揮，一道氣勁由$n"HIY"呼嘯而出，正是大理段氏另一個
     絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第四式"HBYEL+HIC"「玄陽勁」"NOR+HIY"，指勁化為無數條細如針線
     的氣勁奔向各敵。\n
"NOR,me,this_object());

    for(i=0;i<j;i++)
    {
      if(!enemy[i]) continue;
      if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) ) {
        message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
        damage=damage+300;
        enemy[i]->receive_wound("kee",damage,me);
        enemy[i]->apply_condition("bleeding", random(10)+4);
        COMBAT_D->report_status(enemy[i],1);
      }
      else {
        message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
      }
    }
    me->add("force",-400);
    me->add_temp("fan-finger",-1);
    me->set_temp("finger-rest",1);
    call_out("rest",delay,me);
    return 1;
  }
  if(fun >40 && ( me->query("force") > 200) ) {
    message_vision(HIY"
     $N"HIY"將手中$n"HIY"用力一揮，一道氣勁由$n"HIY"呼嘯而出，正是大理段氏另一個
     絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第三式"HBGRN+HIW"「絕陽勁」"NOR+HIY"，指勁有如一條巨大的光柱
     般射向週圍的敵人。\n
"NOR,me,this_object());

    i=random(j);
    if(!enemy[i]) return notify_fail("沒有敵人可以殺。\n");
    if(enemy[i]) {
      if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) ) {
        message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
        damage=damage+200;
        enemy[i]->receive_wound("kee",damage,me);
        enemy[i]->apply_condition("bleeding", random(10)+3);
        COMBAT_D->report_status(enemy[i],1);
      }
      else {
        message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
      }
      me->add("force",-200);
      me->add_temp("fan-finger",-1);
      me->set_temp("finger-rest",1);
      call_out("rest",delay,me);
      return 1;
    }
  }
  if( fun >20 && ( me->query("force") > 150 ) ) {
    message_vision(HIY"
     $N"HIY"將手中$n"HIY"用力一揮，一道氣勁由$n"HIY"呼嘯而出，正是大理段氏另一個
     絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第二式"HBMAG+HIY"「重陽勁」"NOR+HIY"，指勁以極快的速度畫過週
     遭的空氣，極大的聲響充斥著整個空間。\n
"NOR,me,this_object());

    i=random(j);
    if(!enemy[i]) return notify_fail("沒有敵人可以殺。\n");
    if(enemy[i]) {
      if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) ) {
        message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
        damage=damage+100;
        enemy[i]->receive_damage("kee",damage,me);
        enemy[i]->apply_condition("bleeding", random(10)+2);
        COMBAT_D->report_status(enemy[i]);
      }
      else {
        message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
      }
      me->add("force",-150);
      me->add_temp("fan-finger",-1);
      me->set_temp("finger-rest",1);
      call_out("rest",delay,me);
      return 1;
    }
  }
  if(me->query("force") > 100) {
    message_vision(HIY"
     $N"HIY"將手中$n"HIY"用力一揮，一道氣勁由$n"HIY"呼嘯而出，正是大理段氏另一個
     絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第一式"HBRED+HIY"「沉陽勁」"NOR+HIY"，指勁以極快的速度畫過週
     遭的空氣，極大的聲響充斥著整個空間。\n
"NOR,me,this_object());

    i=random(j);
    if(!enemy[i]) return notify_fail("沒有敵人可以殺。\n");
    if(enemy[i]) {
      if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) ) {
        message_vision(HIC"$N"HIC"的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n"NOR,enemy[i]);
        enemy[i]->receive_damage("kee",damage,me);
        enemy[i]->apply_condition("bleeding", random(10)+1);
        COMBAT_D->report_status(enemy[i]);
      }
      else {
        message_vision(HIG"$N"HIG"展開身法，一個閃身躲開了指勁的襲擊。\n"NOR,enemy[i]);
      }
      me->add("force",-100);
      me->add_temp("fan-finger",-1);
      me->set_temp("finger-rest",1);
      call_out("rest",delay,me);
      return 1;
    }
  }
}

int rest(object me)
{
  if(!me) return 1;
  if (me->query("functions/fan-finger/level")!=120) {
    me->add("functions/fan-finger/learned",random(500));
    if (me->query("functions/fan-finger/learned") >= me->query("functions/fan-finger/level")*me->query("functions/fan-finger/level")*10) {
      me->add("functions/fan-finger/level",1);
      me->set("functions/fan-finger/learned",0);
      tell_object(me,HIY);
      tell_object(me,"你的飄陽指勁功\力更上一層。\n" NOR);
    }
  }
  me->delete_temp("finger-rest");
  return 1;
}

int lv_check(object ob)
{
  if(ob->is_busy()) {
    return 1;
  }
  if(ob->query_skill("dodge") >= 150) {
    return 150;
  }
  else {
    return ob->query_skill("dodge");
  }
}

int do_check()
{
//  object me;
  int i;
/*
  if (this_player()) {
    me = this_player();
  }
*/
//  if(!userp(user)) user=previous_object();
  if(!user) return 0;
  i=user->query_temp("fan-finger");
  printf("飄陽扇中還存有%d支氣勁供你使用!!\n",i);
  if(query_heart_beat())
    printf("自動攻擊運作中!!\n");
  else if(query("equipped"))
    set_heart_beat(1);
  return 1;
}

void heart_beat()
{
  int ratio;
  if( !this_object() || !query("equipped") ) {
    set_heart_beat(0);
    return;
  }
  if(!user) user=this_player();
  if(!user) user=previous_object();
  if(!user) return ;
  if(!user->query("env/fan_auto_shoot")) return ;
  if(user->query_temp("finger-rest")) return ;
  if(!user->query_temp("fan-finger")) return ;
  if(user->query("force") <= 100) return ;
  if(!user->is_fighting()) return ;
  if(user->query("functions/fan-finger/level") <90) return ;
  if(user->is_busy()) return ;

  if(wizardp(user)) ratio=95;
  else ratio=50;

  if(ratio >random(100) && !user->query_temp("fan_damage_up"))
    user->set_temp("fan_damage_up",1);

  tell_object(user,sprintf("啟動自動攻擊!!\n"));
  do_shoot();
  return ;
}

int query_autoload()
{
  return 1;
}
