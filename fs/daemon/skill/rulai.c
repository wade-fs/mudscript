// 如來神掌  by weiwei and smooth
//調整skill 為了整合在seventy-two中 by blazakira 2011/10/8

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void ru10(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);

mapping *action = ({
//0
  (["action"     : "$N吐氣揚眉，身形一頓，一道[1;33m金光[0m自右掌中浮出，正是一招[5;1;33m『佛光初現』[0m。",
    "dodge"      : -30,
    "parry"      : -20,
    "damage"     : 50,
    "force"      : 50,
    "damage_type": "瘀傷",
  ]),
//1
  (["action"     : "$N閉目[1m合眉[0m，雙掌合什，倏然欺身而上，一招 [5;1;33m『金頂佛燈』[0m，$n已籠罩$n周身七十二大穴。",
    "dodge"      : -30,
    "parry"      : -20,
    "damage"     : 60,
    "force"      : 60,
    "damage_type": "瘀傷",
  ]),
//2
  (["action"     : "$N大喝一聲，氣衝丹田，一招[5;1;33m『佛動山河』[0m順勢而出，只見掌影飄飄，當真有開山劈石之勢。",
    "dodge"      : -30,
    "parry"      : -20,
    "damage"     : 70,
    "force"      : 70,
    "damage_type": "瘀傷",
    ]),
//3
  (["action"     : "$N氣凝丹田，納氣迴身，掌緣微微上揚，[5;1;33m『佛問迦羅』[0m凌厲的掌氣已使$n擋無可擋，避無可避。",
    "dodge"      : -50,
    "parry"      : -30,
    "damage"     : 80,
    "force"      : 80,
    "damage_type": "瘀傷",
  ]),
//4
  (["action"     : "$N心中一動，揮掌擰身，突地向$n右肩[1m『肩井』[0m穴拍下，只見$n一個[1;32m鷂子翻身[0m，高高躍起，$N身隨意動，掌影順勢上揚，一招[5;1;33m『迎佛西天』[0m，便向$n衝去。",
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 90,
    "force"      : 90,
    "damage_type": "瘀傷",
  ]),
//5
  (["action"     : "$N身形似箭，足不著地，掌緣隱隱有[1m佛光圍繞[0m，霎時一招失傳已久的[5;1;33m『佛光普照』[0m，自掌中發出，[1;31m驚雷[0m般的向$n直射而去。",
    "dodge"      : -60,
    "parry"      : -20,
    "damage"     : 100,
    "force"      : 100,
    "damage_type": "瘀傷",
  ]),
//6
  (["action"     : "$N雙膝盤合，兩掌沉地，身形冉冉向上浮起。[5;1;33m『天佛降世』[0m挾著飛砂走石，雷霆萬鈞之勢撲面迎向$n。",
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 110,
    "force"      : 110,
    "damage_type": "瘀傷",
  ]),
//7
  (["action"     : "$N[1m左手[1;36m離火[0m，[1m右手[31m玄冰[0m，[1m臉色[1;36m忽青[0m[1;31m忽紅[0m，赫然便是[1m如來秘技之[5;1;33m『萬佛朝宗』[0m，煞時間天地變色，佛影飄然，\n只見$n低下斗大的汗珠，[1m如墜[31m煉獄[0m，[1m如墮[36m冰窟[0m。",
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 120,
    "force"      : 120,
    "damage_type": "瘀傷",
  ]),
//8
  (["action"     : "$N[1m心如止水，拈葉微笑[0m。低誦一聲[5;1;33m『 佛 法 無 邊 』[0m，只見$N[1;33m佛光聚頂，祥瑞之氣環身[0m。便在此時，\n$n膽顫驚叫[1m『如來..如來再現』[0m，霎時$N雙眼精光暴射，喝道：[1;32m『八式齊發，毀天滅地』[0m，渾身佛影幢幢，真氣自掌中激射而出。",
    "dodge"      : -50,
    "parry"      : -20,
    "damage"     : 130,
    "force"      : 130,
    "damage_type": "瘀傷",
    "post_action": (: call_other , __FILE__, "conti" :),
  ]),
});

void conti(object me, object victim, object weapon, int damage)
{
  int i,level;
  if( !me || !victim ) return;
  level=(int)(me->query_skill("rulai",1)/10);
  if( !level ) level=(int)(me->query_skill("seventy-two",1)/10);
  if( level > 6 )
  {
    if( me->query_temp("rulai") == 0 && me->query("class")=="bonze" )
    {
      me->set_temp("rulai",1);
      message_vision(sprintf("\n[35;1m$N一手指天，一手指地，大喝一聲[5;37m 『 上天下地，唯我獨尊！ 』[0m\n"),me);
      for(i=1;i<=10;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      me->delete_temp("rulai");
      me->start_busy(1);
    }
  } 
}

mapping query_action(object me,object weapon)
{
  int skill_level, limit;
  object victim;
  victim = offensive_target(me);

  skill_level = (int)(me->query_skill("rulai", 1));
  if( !skill_level )skill_level = (int)(me->query_skill("seventy-two", 1));
  limit= (int)(skill_level/10);
  // 殺氣少攻擊變多 1/3 的出現機會
  if(me->query("bellicosity") < 50 && random(100) < 30 && limit > 7 )
  {
    me->set_temp("rulais",1);
    message_vision(HIC"\n\n$N臉露慈笑，一陣祥和之氣從$N的身上顯現出來，但手中的掌力卻越摧越強！\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim , weapon, TYPE_QUICK);
    me->delete_temp("rulais",1);
  }
  if (limit < 4 )
    return action[random(4)];
  else if (limit < 7 )
    return action[random(limit)];
  else
    return action[random(5)+4];
}

int valid_enable(string usage) 
{
  return (usage=="unarmed") || (usage=="parry");
}

int valid_learn(object me)
{
  return 1;
}

int practice_skill(object me)
{
  return 1;
}
