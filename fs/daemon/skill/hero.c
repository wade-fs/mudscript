// by frequency
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 by blazakira 2011/4/23

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void busy(object me, object victim, object weapon, int damage);
void sword(object me, object victim, object weapon, int damage);
void blade(object me, object victim, object weapon, int damage);
void create() { seteuid(getuid()); }

mapping *action = ({

//1
([ "action":
"$N使出" + HIC + "『" + HIW + "英雄真經" + HIC + "』" + NOR + "上所載的" + HIW + "『" + HIY + "無雙拳" + HIW + "』" + NOR + "，沈重渾厚的拳勁有如砲火般在$n身上不斷炸裂。",
        "damage": 240,
        "force":  200,
        "dodge":  -120,
        "parry":  -120,
        "damage_type":  "內傷",
        "weapon": "重拳",
        "post_action": (: busy :),
]),

//2
([ "action":
"$N氣御紙劍，運起" + HIC + "『" + HIW + "英雄真經" + HIC + "』" + NOR + "上所載的" + HIW + "『" + CYN + "虛空御天劍" + HIW + "』" + NOR + "，紙劍靈動，在$n身邊不住穿梭!!",
        "damage": 280,
        "force":  240,
        "dodge":  -140,
        "parry":  -140,
        "damage_type":  "削傷",
        "weapon": "紙劍",
        "post_action": (: sword :),
]),

//3
([ "action":
"$N木刀出鞘，使出" + HIC + "『" + HIW + "英雄真經" + HIC + "』" + NOR + "中所載的" + HIW + "『" + HIR + "超霸絕刀" + HIW + "』" + NOR + "，威猛無儔的霸刀絕罡\逼得$n只能撤招自守!!",
        "damage": 300,
        "force":  250,
        "dodge":  -150,
        "parry":  -150,
        "damage_type": "斬傷",
        "weapon": "木刀",
        "post_action": (: blade :),
]),
});

void busy(object me, object victim, object weapon, int damage)
{
  if(random(2)==1 && me->query_skill("hero",1) >= 100)
  {
    message_vision(HIY + "\n$N左執木刀，右持紙劍，推動" + HIW + "ξ" + BBLU+HIC + "本來無一劍" + NOR + "" + HIW + "ξ" + HIY + "和" + HIW + "ξ" + HBMAG+HIG + "柳葉霸刀" + NOR + "" + HIW + "ξ" + HIY + "刀劍合璧，

      " + HIW + "《" + HIR + "化氣為劍-劍無形、" + HIG + "聚葉成刀-刀無影" + HIW + "》" + HIY + "

 劍氣、刀罡\的瘋狂怒斬，幾乎將方圓百呎夷為平地，$n驚恐得一步也無法移動。\n" + NOR,me,victim);	
    if(!victim->is_busy())  victim->start_busy(1);
    victim->receive_damage("kee",1500,me);
    COMBAT_D->report_status(victim);
  }
  else if(random(2)==1) COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sword(object me, object victim, object weapon, int damage)
{
  int i,j;
  if(random(2)==1 && me->query_skill("hero",1) >= 100)
  {
    j = 1 + random(7);
    message_vision(HIY + "\n $N以" + HIW + "『" + HIM + "本來無一物神功" + HIW + "』" + HIY + "推動" + HIW + "「" + CYN + "虛空御天劍" + HIW + "」" + HIY + "化氣為劍，使出劍道最高境界之" + HIW + "『" + HIC + "本來無一劍" + HIW + "』\n\n" + NOR,me);
    for(i=0;i<j;i++)
    {
      message_vision(HIB + "滿天劍氣縱橫交錯，密密麻麻的劍網將$N割得遍體鱗傷。\n" + NOR,victim);
      victim->receive_damage("kee",400,me);
      COMBAT_D->report_status(victim);
    }
  }
  else if(random(2)==1) COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void blade(object me, object victim, object weapon, int damage)
{
  int i,j;
  if(random(2)==1 && me->query_skill("hero",1) >= 100)
  {
    j = 1 + random(7);
    message_vision(HIC + "\n《" + GRN + "刀，可大、可小、可近、可遠，霸道與飄逸，兩者兼得" + HIC + "》" + HIY + "
  
   $N" + HIW + "『" + HIM + "本來無一物神功" + HIW + "』" + HIY + "更上一層，迫出刀法巔峰之境的" + HIW + "『" + HIG + "柳葉霸刀" + HIW + "』\n\n" + NOR,me);

    for(i=0;i<j;i++)
    {
      message_vision(MAG + "威猛無匹的霸刀罡\氣，轉瞬間石破天驚般劈中$N。\n" + NOR,victim);
      victim->receive_wound("kee",300,me);
      COMBAT_D->report_status(victim);
    }
  }
  else if(random(2)==1) COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

mapping query_action(object me, object weapon)
{
  return action [random(3)];
}

int valid_learn(object me)
{
  return 1;
}

int valid_enable(string usage)
{
  return (usage=="unarmed"||usage=="parry");
}

int practice_skill(object me)
{
  me->receive_damage("gin", 5, me);
  me->receive_damage("kee", 30, me);
  me->add("force", -1);
  return 1;
}
