//改變使用者的判定為me = environment(this_object()) 與 wear形式為int wear() (參考殺意魔戒) by blazakira 2011/10/11

#include <weapon.h>
#include <ansi.h>
inherit STABBER;

int lv_check(object target);
int do_shoot();
object user;
object ob;
int be,bb,k,sp,qq,co,st;

void create()
{
  set_name(YEL + "凌微雲扇飄" + NOR,({"lin-cloud-fan","fan"}) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","純靈吟所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，輕巧\n卻不失威力，隱隱透著幾股雲氣。\n");
    set("unit", "把");
    set("value",20000);
    set("sharp",9);
    set("material","blacksteel");
    set("e-weapon",1);
    set("no_give",1);
    set("no_steal",1);
    set("need_exp",3000000);
  }
  init_stabber(100);
  set("wield_msg",CYN + "$N" + CYN + "拿起$n" + CYN + "，$n" + CYN + "雲氣由扇身隱隱透發出來!!\n" + NOR);
  set("unwield_msg","$N輕輕卸下$n，$n雲氣漸漸被$n吸收殆盡。\n" + NOR);
  setup();
}

void init()
{
  ob=this_object();
  add_action("do_shoot","shoot");
//  add_action("do_drop","drop");
//  add_action("do_auc","auc");
//  add_action("do_wield","wield");
//  add_action("do_unwield","unwield");
}

int wield()
{
  int result = ::wield();
  if( query("equipped"))
  {
    user=environment();
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  int result = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return result;
}
/*
int do_wield(string str)
{
  int uexp;
//  ::wield();
  if( !query("equipped") )
  {
    user = this_player();
    uexp = user->query("combat_exp");
    if( uexp < 3000000 )
    {
      message_vision("$N的經驗並不足以完全支配這樣的神兵利器!!\n" + NOR,user);
      set_heart_beat(0);
    } else {
//    message_vision(CYN + "$N" + CYN + "拿起$n" + CYN + "，$n" + CYN + "雲氣由扇身隱隱透發出來!!\n" + NOR,user,ob);
      set_heart_beat(1);
    }
  }
}

int do_drop(string str)
{
  if(str=="lin-cloud-fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
  message_vision("$N輕輕卸下$n，$n雲氣漸漸被$n吸收殆盡。\n" + NOR,user,ob);
  set_heart_beat(0);
  }
}

int do_unwield(string str)
{
  if(str=="lin-cloud-fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
//  message_vision("$N輕輕卸下$n，$n雲氣漸漸被$n吸收殆盡。\n" + NOR,user,ob);
  set_heart_beat(0);
  }
}

int do_auc(string str)
{
  if(str=="lin-cloud-fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
  message_vision("$N輕輕卸下$n，$n雲氣漸漸被$n吸收殆盡。\n" + NOR,user,ob);
  set_heart_beat(0);
  }
}
*/
void heart_beat()
{
  object *enemy;
  int i,be,ratio;

  ratio = 30;

  if( !ob || !user || !objectp(user) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }

  if( !user->query_skill("stabber") )
  {
    be = random(120);
  } else {
    be = user->query_skill("stabber");
  }

  if( be > 150) be=150;

  k = user->query_int();
  sp = user->query_spi();
  co = user->query_cor();
  st = user->query_str();
  qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
  if( user->query("class") == "scholar" )
  {
    qq = qq*1.25;
    be = be*1.25;
  }

  if( user->is_fighting() )
  {
    if( be > random(500) )
    {
      enemy=user->query_enemy();
      if(!enemy) return;
      i=random(sizeof(enemy));
      if( environment(user) == environment(enemy[i]) )
        if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
        {
          message_vision("$n" + HIB + "的雲氣轉為濃烈而鋒利，$N" + HIB + "只覺視線模糊，已被鋒利雲氣劃破數處肌膚!!\n" + NOR,enemy[i],ob);
          enemy[i]->receive_wound("kee",(int)(qq+be),user);
          COMBAT_D->report_status(enemy[i], 1);
        } else
          message_vision(BLU + "$N" + BLU + "向後一閃，避開了這股鋒利的雲氣!!\n" + NOR,enemy[i],ob);
    }
  }

  if(ratio >random(100) && !user->query_temp("fan_damage_up"))
    user->set_temp("fan_damage_up",1);
  do_shoot();
  return;
}

int do_shoot()
{
  object me,*enemy;
  int i,j,fun,damage,k,sk_lv,power;

  me=user;

  if( !me->query("can_use_cloud") )
    return 0;

  if(!me) return notify_fail("無法使用<建議unwield後再wield試試!!\n");
  enemy=me->query_enemy();
  j=sizeof(enemy);
  fun=me->query("functions/fan-finger/level");
  damage=fun*(random(7)+1);
  if(damage < 100 )
    damage=100;
  if(damage > 700)
    damage=700;

  if(!query("equipped"))
    return 0;

  if(me->is_busy())
    return 0;

  if(!me->query_temp("fan-finger"))
    return notify_fail(HIC + "你並沒有鍊化一陽指氣到" + HIC + "飄" + HIY + "陽" + HIW + "扇裡!!\n" + NOR);

  if(!me->is_fighting())
    return notify_fail(HIY + "只有在戰鬥中才可以使用「飄陽指勁」。\n" + NOR);

  if(me->query("force") <= 100)
    return notify_fail(HIR + "你的內力已經用盡，再沒有內力來發出「飄陽指勁」。\n" + NOR);

  if(me->query_temp("finger-rest",1))
    return notify_fail(HIY + "你因為使出「飄陽指勁」，使得自身的內息翻滾不定，暫時無法再使出「飄陽指勁」。\n" + NOR);

  if(me->query_temp("fan_damage_up")) {
    me->delete_temp("fan_damage_up");
    power=(int)(me->query("combat_exp")/2000000+1);
    damage=damage*power;
    if(damage > 2000) damage=2000;
    me->add("force",-500);
    message_vision(BLINK+HIY"\n$N" + HIY + "領悟到指勁揮出時角度的重要性，手中的"+NOR+"$n"+BLINK+HIY+"以一個敵人完全無法閃躲的角度揮了出去!!\n" + NOR,me,ob);
  }
  if(wizardp(me))
    tell_object(me,sprintf("damage=%d\n",damage));
  if(fun > 80 && ( me->query("force") > 600 ))
  {
    if(fun>=100 && me->query_temp("fan-finger") >= 5 && (20 > random(100) || wizardp(me)) && me->query("force")>600 && me->query("env/飄陽扇連擊") )
    {
      message_vision(HIM + "
      $N" + HIM + "忽然領悟到了"BLINK+HIR"「飄陽指勁」"NOR+HIM"中"BLINK+HIY"「飄渺虛無，真陽縱橫」"NOR+HIM"的真意，口中大喝
      "HBRED+HIY"「飄～陽～指～勁～巧～連～環」"NOR+HIM"，手中$n" + HIM + "一揚，五道不同顏色的指勁騰空
      而出，如有靈性般的奔向各敵。\n\n" + NOR,me,ob);
      i=random(j);
      if(enemy[i]) {
        if( environment(user) == environment(enemy[i]) )
          if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") >100000 )
          {
            message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第一式"HBRED+HIY"「沉陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
            enemy[i]->receive_wound("kee",damage,me);
            enemy[i]->apply_condition("bleeding", random(10)+1);
            COMBAT_D->report_status(enemy[i],1);
          }
          else
          {
            message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
          }
      }
      i=random(j);
      if(enemy[i]) {
        if( environment(user) == environment(enemy[i]) )
          if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 100000 )
          {
            message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第二式"HBMAG+HIY"「重陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
            damage=damage+100;
            enemy[i]->receive_wound("kee",damage,me);
            enemy[i]->apply_condition("bleeding", random(10)+2);
            COMBAT_D->report_status(enemy[i],1);
          }
          else
          {
            message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
          }
      }
      i=random(j);
      if(enemy[i]) {
        if( environment(user) == environment(enemy[i]) )
          if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") > 100000 ) {
            message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第三式"HBGRN+HIW"「絕陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
            damage=damage+200;
            enemy[i]->receive_wound("kee",damage,me);
            enemy[i]->apply_condition("bleeding", random(10)+3);
            COMBAT_D->report_status(enemy[i],1);
          }
          else
          {
            message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
          }
      }
      for(i=0;i<j;i++)
      {
        if(!enemy[i]) continue;
        if( environment(user) == environment(enemy[i]) )
          if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") >100000 )
          {
            message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第四式"HBYEL+HIC"「玄陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
            damage=damage+300;
            enemy[i]->receive_wound("kee",damage,me);
            enemy[i]->apply_condition("bleeding", random(10)+4);
            COMBAT_D->report_status(enemy[i],1);
          }
          else
          {
            message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
          }
      }
      for(i=0;i<j;i++)
      {
        if(!enemy[i]) continue;
        if( environment(user) == environment(enemy[i]) )
          if(((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30)) || me->query("force") >100000 )
          {
            message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"中的第五式"BLINK+HIC"「靈陽勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
            damage=damage+400;
            enemy[i]->receive_wound("kee",damage,me);
            enemy[i]->apply_condition("bleeding", random(10)+5);
            COMBAT_D->report_status(enemy[i],1);
          }
          else
          {
            message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
          }
      }
      me->add("force",-2000);
      message_vision(HIY + "$N因為使出了"BLINK+HIR"「飄陽指勁」"NOR+HIY"的連續招，體內的內息狂洩而出，體內的內力嚴重的流失了!!!\n" + NOR,me);
      me->add_temp("fan-finger",-5);
      me->set_temp("finger-rest",1);
      call_out("rest",7,me);
      return 1;
    }
    message_vision(HIY + "
        $N" + HIY + "將手中$n" + HIY + "用力一揮，一道氣勁由$n" + HIY + "呼嘯而出，正是大理段氏另一個
        絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第五式"BLINK+HIC"「靈陽勁」"NOR+HIY"，指勁化繁為簡，如有靈性
        般的奔向各敵。\n\n" + NOR,me,ob);
    for(i=0;i<j;i++)
    {
      if(!enemy[i]) continue;
      if( environment(user) == environment(enemy[i]) )
        if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) )
        {
          message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
          damage=damage+400;
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+5);
          COMBAT_D->report_status(enemy[i],1);
        }
        else
        {
          message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
        }
    }
    me->add("force",-600);
    me->add_temp("fan-finger",-1);
    me->set_temp("finger-rest",1);
    call_out("rest",5,me);
    return 1;
  }
  if(fun >60 && ( me->query("force") > 400 ))
  {
    message_vision(HIY + "
        $N" + HIY + "將手中$n" + HIY + "用力一揮，一道氣勁由$n" + HIY + "呼嘯而出，正是大理段氏另一個
        絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第四式"HBYEL+HIC"「玄陽勁」"NOR+HIY"，指勁化為無數條細如針線
        的氣勁奔向各敵。\n\n" + NOR,me,ob);
    for(i=0;i<j;i++)
    {
      if(!enemy[i]) continue;
      if( environment(user) == environment(enemy[i]) )
        if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) )
        {
          message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
          damage=damage+300;
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+4);
          COMBAT_D->report_status(enemy[i],1);
        }
        else
        {
          message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
        }
    }
    me->add("force",-400);
    me->add_temp("fan-finger",-1);
    me->set_temp("finger-rest",1);
    call_out("rest",5,me);
    return 1;
  }
  if(fun >40 && ( me->query("force") > 200) )
  {
    message_vision(HIY + "
        $N" + HIY + "將手中$n" + HIY + "用力一揮，一道氣勁由$n" + HIY + "呼嘯而出，正是大理段氏另一個
        絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第三式"HBGRN+HIW"「絕陽勁」"NOR+HIY"，指勁有如一條巨大的光柱
        般射向週圍的敵人。\n\n" + NOR,me,ob);
    i=random(j);
    if(!enemy[i]) i=0;
    if(enemy[i]) {
      if( environment(user) == environment(enemy[i]) )
        if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) )
        {
          message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
          damage=damage+200;
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+3);
          COMBAT_D->report_status(enemy[i],1);
        }
        else
        {
          message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
        }
      me->add("force",-200);
      me->add_temp("fan-finger",-1);
      me->set_temp("finger-rest",1);
      call_out("rest",5,me);
      return 1;
    }
  }
  if( fun >20 && ( me->query("force") > 150 ) )
  {
    message_vision(HIY + "
        $N" + HIY + "將手中$n" + HIY + "用力一揮，一道氣勁由$n" + HIY + "呼嘯而出，正是大理段氏另一個
        絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第二式"HBMAG+HIY"「重陽勁」"NOR+HIY"，指勁以極快的速度畫過週
        遭的空氣，極大的聲響充斥著整個空間。\n\n" + NOR,me,ob);
    i=random(j);
    if(!enemy[i]) i=0;
    if(enemy[i]) {
      if( environment(user) == environment(enemy[i]) )
        if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) )
        {
          message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
          damage=damage+100;
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+2);
          COMBAT_D->report_status(enemy[i],1);
        }
        else
        {
          message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
        }
      me->add("force",-150);
      me->add_temp("fan-finger",-1);
      me->set_temp("finger-rest",1);
      call_out("rest",5,me);
      return 1;
    }
  }
  if(me->query("force") > 100)
  {
    message_vision(HIY + "
        $N" + HIY + "將手中$n" + HIY + "用力一揮，一道氣勁由$n" + HIY + "呼嘯而出，正是大理段氏另一個
        絕招"BLINK+HIR"「飄陽指勁」"NOR+HIY"中的第一式"HBRED+HIY"「沉陽勁」"NOR+HIY"，指勁以極快的速度畫過週
        遭的空氣，極大的聲響充斥著整個空間。\n\n" + NOR,me,ob);
    i=random(j);
    if(!enemy[i]) i=0;
    if(enemy[i]) {
      if( environment(user) == environment(enemy[i]) )
        if((fun+20+random(30)) > random(lv_check(enemy[i]))+random(30) )
        {
          message_vision(HIC + "$N" + HIC + "的身體不幸被"BLINK+HIR"「飄陽指勁」"NOR+HIC"所穿透，鮮血不斷的從傷口流出。\n" + NOR,enemy[i]);
          enemy[i]->receive_wound("kee",damage,me);
          enemy[i]->apply_condition("bleeding", random(10)+1);
          COMBAT_D->report_status(enemy[i],1);
        }
        else
        {
          message_vision(HIG + "$N" + HIG + "展開身法，一個閃身躲開了指勁的襲擊。\n" + NOR,enemy[i]);
        }
      me->add("force",-100);
      me->add_temp("fan-finger",-1);
      me->set_temp("finger-rest",1);
      call_out("rest",5,me);
      return 1;
    }
  }
}

int rest(object me)
{
  if(!me) return 1;
  if(me->query("functions/fan-finger/level")!=120)
  {
    me->add("functions/fan-finger/learned",random(500));
    if(me->query("functions/fan-finger/learned") >= me->query("functions/fan-finger/level")*me->query("functions/fan-finger/level")*10)
    {
      me->add("functions/fan-finger/level",1);
      me->set("functions/fan-finger/learned",0);
      tell_object(me,HIY);
      tell_object(me,"你的飄陽指勁功\力更上一層。\n" + NOR);
    }
  }
  me->delete_temp("finger-rest");
  return 1;
}

int lv_check(object target)
{
  if(ob->query_skill("dodge") >=150)
    return 150;
  else
    return ob->query_skill("dodge");
}
