//by poloer
// sky-strike(滅天拳)
//排版 與增加使用者與對手存在與否的判斷 by blazakira 2011/9/18

inherit SKILL;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>

void burn(object me, object victim, object  weapon, int damage);

mapping *action = ({
  (["action"     : "$N右手連拍數招虛招﹐左掌突然使出一招陰險無比的" + HIR + "『喪盡天良』" + NOR + "化虛為實擊向$n的$l",
    "parry"      : -60,
    "dodge"      : -60,
    "force"      : 250,
    "damage"     : 280,
    "post_action": (: burn :),
    "damage_type": "瘀傷"
  ]),
  (["action"     : "$N的左掌忽然反拍﹐掌式充滿傲然氣勢突如其來地使出一招" + HIM + "『天奈我何』" + NOR + "擊向$n$l",
    "parry"      : -60,
    "dodge"      : -60,
    "force"      : 250,
    "damage"     : 270,
    "post_action": (: burn :),
    "damage_type": "瘀傷"
  ]),
  (["action"     :    "$N將左手畫圓右掌作方﹐跟著使出一招" + HIC + "『無法無天』" + NOR + "﹐雙掌化成無數掌影紛紛擊向$n",
    "parry"      : -60,
    "dodge"      : -60,
    "force"      : 250,
    "damage"     : 280,
    "post_action": (: burn :),
    "damage_type": "瘀傷"
  ]),
  (["action"     : "$N左手連出虛招﹐接著右掌一翻使出" + HIC + "『隻手遮天』" + NOR + "﹐由上而下凶猛地擊向$n的$l",
    "parry"      : -60,
    "dodge"      : -60,
    "force"      : 260,
    "damage"     : 280,
    "post_action": (: burn :),
    "damage_type": "瘀傷"
  ]),
  (["action"     : "$N看準$n的破綻﹐一招" + HIR + "『天狗食日』" + NOR + "左右開弓連擊出兩掌挾著驚天氣勢分取$n的要害",
    "parry"      : -60,
    "dodge"      : -60,
    "force"      : 300,
    "damage"     : 280,
    "post_action": (: burn :),
    "damage_type": "瘀傷"
  ]),
  (["action"     : "$N撲身躍向$n﹐雙手平推﹐使出一招" + HIB + "『暗無天日』" + NOR + "雙掌驀然爆發黑氣遮蔽得天地黯然無光直擊向$n",
    "parry"      : -60,
    "dodge"      : -60,
    "force"      : 350,
    "damage"     : 280,
    "post_action": (: burn :),
    "damage_type": "瘀傷"
  ]),
});

void burn(object me, object victim, object  weapon, int damage)
{
  int burn;
  if(!me || !victim) return;
  burn=victim->query_condition("burn");
  message_vision("$N的真氣化為一條黑龍往$n的身上纏繞,使得$n的真氣慢慢的流失\n",me,victim);
  victim->apply_condition("burn",burn+1);
  victim->receive_damage("kee",30,me);
  victim->add("force",-40);
  COMBAT_D->report_status(victim);
}

int valid_enable(string usage)
{
  return (usage=="unarmed" || usage=="parry");
}

mapping query_action(object me, object weapon)
{
  int i,force,kee,burn;
  object victim,*enemy;
  if(!me) return;
  enemy = me->query_enemy();
  if(!enemy)
    return action[random(sizeof(action))];
  i=sizeof(enemy);
  victim = enemy[random(i)];
  burn=victim->query_condition("burn");
  force=victim->query("force",1);
  kee=220;
  if( random(100) < 10){
    message_vision(HIC + "
$N大喝說：「哼！讓你見識見識炎龍谷主的絕招，下地獄去吧！」


" + HIB + "                 滅絕一擊！      " + NOR + "


" + HIG + "           ****晴天霹靂****      " + NOR + "
" + HIR + "$N口中喃喃自語，雙手在胸前結成魔手印，瞬間一道真氣往天空射去，忽然間
天空魔雲密怖，一道黑色的閃電往$n劈去" + NOR + "
結果$n被雷劈中，全身麻斃，身體都不能動彈！\n",me,victim);
    victim->receive_damage("kee",(int)kee,me);
    COMBAT_D->report_status(victim);
    message_vision("


" + HIG + "           ****翻天覆地****    " + NOR + "
" + HIR + "$N狂笑一聲，雙掌合為兩道真氣往天空和地面指去，驀然地面及天空產生
變化，瞬間天搖地動，混濁之氣隨之合為一體往$n襲去
" + NOR + "結果$n被混濁之氣封住任督二穴，身體漸漸感到虛弱\n",me,victim);
    victim->receive_damage("kee",220,me);
    me->start_busy(1);
    COMBAT_D->report_status(victim);
  }
  return action[random(sizeof(action))];
}
