// rain-throing.c
// By Swy 最後修正 QC 98/6/23
// 加強威力以符現今 fs by swy
// 稍微修改提昇威力 by unfinished
//增加判斷於戰鬥中換武器所導致出問題的可能性 by blazakira 2011/3/19

#include <combat.h>
#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);
mapping *action = ({
  ([ "action": "$N將手中$w用力一鄭﹐一招「"HIY"點星雨"NOR"」﹐只見一道白光往$n$l射去",
     "dodge":        -30,
     "damage":       250,
     "force":        150,
     "parry":        -30,
     "damage_type" : "射傷",
     "post_action" : (: throw_weapon :),
     ]),
  ([ "action": "$N手中散出一道白光﹐一招「"HIC"散雷風"NOR"」$w飄浮不定的往$n$l而去",
     "dodge":        -30,
     "damage":       225,
     "force":        175,
     "parry":        -30,
     "damage_type" : "射傷",
     "post_action" : (: throw_weapon :),
     ]),
  ([ "action": "$N一招「"HIW"星燈萬雨"NOR"」﹐射出的$w散出無數殘影往$n而去",
     "dodge":        -30,
     "damage":       200,
     "force":        200,
     "parry":        -30,
     "damage_type" : "射傷",
     "post_action" : (: throw_weapon :),
     ]),
  ([ "action": "$N一招「"HIG"歿\神搶親"NOR"」﹐射出的$w有如俇鷹雄飛﹐往$n$l直奔而去",
     "dodge":        -40,
     "damage":       175,
     "force":        225,
     "parry":        -40,
     "damage_type" : "射傷",
     "post_action" : (: throw_weapon :),
     ]),
  ([ "action": "$N一招「風起雲湧」﹐射出的$w以極端的速度飛往$n的$l去",
     "dodge":        -55,
     "damage":       150,
     "force":        250,
     "parry":        -50,
     "damage_type" : "射傷",
     "post_action" : (: throw_weapon :),
     ]),
});

int valid_learn(object me)
{
  object ob;

  if(me->query_skill("throwing",1)<20)
    return notify_fail("要練霸雨螫魂要先有相當的暗器基礎。\n");

  if( !(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type")!="throwing")
    return notify_fail("你手上要有暗器才能練霸雨螫魂。\n");

  return 1;
}

int valid_enable(string usage)
{
  return usage=="throwing" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 30
      || (int)me->query("force") < 3 )
    return notify_fail("你的內力或氣不夠﹐不能練霸雨螫魂。\n");
  me->receive_damage("kee", 30,me);
  me->add("force", -3);
  return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("killer")+"/rain-throwing/"+action;
}
void throw_weapon(object me, object victim, object weapon, int damage)
{
  object wp=me->query_temp("weapon");
  object *enemy=me->query_enemy();
  int i=sizeof(enemy);
  int am ;
  int j;
  int h=me->query("quest/island")*8;
  int cor=me->query_cor();
  if(me->query("bellicosity") < 20 || me->query("force") < 100)
  {
    message_vision(HIR"$N無法凝聚殺氣，殺招無法使出。\n"NOR,me);
    return;
  }
  if(me->query_temp("star_kill"))
  {
    //return ;
  }
  if( objectp(weapon) ) 
  {
    if( (int)weapon->query_amount()==1 ) 
    {
      weapon->unequip();
      tell_object(me, "\n你的" + weapon->query("name") + "用完了﹗\n\n");
    }
    //此為Leei加的
    else  
    {
      am=random(3)+1;


      //第一特殊技 最大傷害值約270 發動機率約50% 平均135
      if ((int)weapon->query_amount() >30 && me->query_skill("throwing") >=random(320) && (int)me->query("force") > 20)  
      {
        message_vision(sprintf(HIC"\n$N再抓起一把"+weapon->query("name")+""+HIC+"對準$n快速地射去,$n躲避不及,全部命中。\n"NOR),me,victim);
        victim->receive_damage("kee",10+me->query_skill("rain-throwing")+me->query_skill("throwing"),me);
        me->add("force",-10);
        me->add("bellicosity", -10);

        COMBAT_D->report_status(victim);
        if(userp(me))
        weapon->add_amount(-am);
      }

      //第二特殊技 少量busy 發動機率約25%  連擊時不發生
      if ((int)weapon->query_amount() >30 && me->query_skill("throwing") >=random(800) && (int)me->query("force") > 20 && me->query_temp("star_kill")!=1)  
      {
        message_vision(sprintf(HIY"\n$N抓準時機丟出一把"+weapon->query("name")+""+HIY+"對準$n的下盤射去, $n連連躲避, 忙的手忙腳亂。\n"NOR),me,victim);
        victim->start_busy(1);
        me->add("force",-20);
        me->add("bellicosity", -10);
        if(userp(me))
        weapon->add_amount(-am);
      }

      //第三特殊技 最大傷害值約600 發動機率約20% 平均120 會造成流血
      if ((int)weapon->query_amount() >30 && me->query_skill("throwing") >=random(800) && (int)me->query("force") > 20 )  
      {
        message_vision(sprintf(HIG"\n$N將內勁注入"+weapon->query("name")+""+HIG+", $n躲避不及, 被擊中要害而大量流血。\n"NOR),me,victim);
        victim->receive_damage("kee",340+me->query_skill("rain-throwing")+me->query_skill("throwing"),me);
        victim->apply_condition("bleeding", random(3)+2);
        COMBAT_D->report_status(victim);
        if(userp(me))
        weapon->add_amount(-am);
        me->add("bellicosity", -10);
        me->add("force",-20);
        weapon->add_amount(-am);

      }

      //第四特殊技 全體傷害技 單體最大傷害值約500 發動機率約20% 連擊時不發動  exp 400萬以上限制 大量耗費武器數量  需解過任務
      if ((int)weapon->query_amount() >300 && me->query("combat_exp") >= 4000000 && me->query_skill("throwing") >=random(800) && me->query("quest/island")!=0 && me->query("bellicosity") > 500 && me->query_temp("star_kill")!=1 && me->query("force") > 200 )  
      {
        message_vision(sprintf(HIW"\n                     $N身型晃動, 身手越來越快, "HIR"殺意"HIW"也跟著高漲～～～\n"NOR),me,victim);
        message_vision(sprintf(HIG"                         在充滿殺意的雙眼中, $N似乎有所頓悟！！\n\n"NOR),me,victim);
        message_vision(sprintf(HIW"               $N爆發殺氣, 使出「"HIR"霸 雨 螫 魂 "HIW"之 "HIC"ψ 漫    天    花    雨 ψ"HIW"」 \n"NOR),me,victim);
        message_vision(sprintf(HIY"                       剎那間, 眼前只見如雨水般的"+weapon->query("name")+""HIY"在風中飛舞！！\n\n"NOR),me,victim);
        am=random(50)+1;
        if(userp(me))
        weapon->add_amount(-am);
        me->add("force", -40);
        me->add("bellicosity", -20);
        while(i--) {
          if(!me || !enemy[i]) continue;
          if(environment(me)!=environment(enemy[i])) continue;
          if(random(me->query_skill("throwing")) > 30) {
            message_vision(HIR"$N無法躲過這一擊, 全身上下被割的鮮血直流！\n"NOR,enemy[i]);
            enemy[i]->receive_wound("kee",240+me->query_skill("rain-throwing")+me->query_skill("throwing"),me);
            enemy[i]->apply_condition("bleeding", random(3)+2);
            COMBAT_D->report_status(enemy[i]);
          }
          else {
            message_vision(YEL"$N閃過如雨水般的攻擊, 卻也搞的忙手忙腳亂, 狼狽不堪！\n"NOR,enemy[i]);
            COMBAT_D->report_status(enemy[i]);
            enemy[i]->start_busy(1); }
        }
      }


      //移到此處的千古恨特攻 傷害值約400 發動機率40%  連擊時不發生 威力隨著cor上升增加
      if (wp->query("id")=="hate knife" && me->query("quest/island")!=0 && me->query("bellicosity") > 500 && me->query_temp("star_kill")!=1 && me->query("force") > 200 )
      {
        if(me->query_skill("throwing") >= random(400))
        {
          am = random(10)+10;
          if(userp(me))
          weapon->add_amount(-am);

          message_vision(HIC"\n======  "HIW"$N 使 出 霸 雨 螫 魂 奧 義 "HIY"流 星 幻 雨 "HIC" ====== \n\n"NOR,me);
          message_vision(HIM"$N擲出的"HIR"千古恨"HIM"突然在空中幻化出數條殘影, 令$n無法捉摸!!\n"NOR,me,victim);
          for(j=0;j<(random(cor)+2)/2;j++)
          {
            message_vision(HIW"\n$N在錯愕間已被千古恨的殘影掃中, 割出一條傷口, 鮮血直流!!\n"NOR,victim);
            victim->receive_wound("kee",h,me);  // h 值最高24
            COMBAT_D->report_status(victim);
            me->add("bellicosity", -5);
            me->add("force",-5);
          }
        } 
      }

      //連擊  多一次攻擊發動率 40% 解謎限定 不如dagger連擊多
      //不能連擊再連擊
      if (weapon && me->query_skill("throwing") > random(400) && (int)weapon->query_amount() >30 && me->query("quest/island") >0
          && !me->query_temp("star_kill") 
         )
      {
        am = random(3)+1;
        if(userp(me))
          weapon->add_amount(-am);
        me->set_temp("star_kill",1);
        am  = me->query_skill("throwing") / 50;
        am  =  1 + random(am/2) + am/2;
        while( (am--) != 0 )
        {
          message_vision(sprintf(HIW"\n$N眼見機不可失, 掏出"+weapon->query("name")+""+HIW+"對$n發動追擊。\n"NOR),me,victim);
          COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
          me->add("bellicosity", -20);
          me->add("force", -30);
        }
        
        me->delete_temp("star_kill");
      }


    }
    //到此為止
    if(userp(me) && weapon && (int)weapon->query_amount() > 1 ) //weapon不存在 應該是扣完了或換武器 by blazakira 2011/3/18
    weapon->add_amount(-1);
  }
}


