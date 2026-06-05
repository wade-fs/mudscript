// 天殘手 by roger
// 這是魔界mob 的專用skill之一
#include <ansi.h>
#include <combat.h>
inherit SKILL;

void blood(object me, object victim, object  weapon, int damage);
void super(object me, object victim, object  weapon, int damage);
string *parry_msg= ({
   "$n雙手往上一翻, 雙腳蹲了個馬步, 使出一招「妖魔聚鼎」, 將妖氣凝聚於全身上下, 硬生生的把$N的招式接了下來!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖攔路」, 三指由中宮飛快的探向$n的咽喉, 破解了$N的攻勢。\n",
});

mapping *action = ({
([ "action" : HIM + "$N使出魔域" + HIB + "『" + HIM + "天殘手" + HIB + "』" + HIM + "中的絕招" + HIB + "『" + HIM + "天殘刀氣" + HIB + "』" + HIM + "，右手一動一道刀氣便直奔向$n剎那間$n的$l已被割傷...\n" + NOR,
        "dodge":   20,
        "parry":   20,
        "damage":   250,
        "force":    290,        
        "damage_type" : "割傷"
        
]),

([ "action" :HIM + "$N使出魔域" + HIB + "『" + HIM + "天殘手" + HIB + "』" + HIM + "中的" + HIB + "『" + HIM + "天殘鎖功\手" + HIB + "』" + HIM + "伸手遙抓一探便使得$n的內息無法發揮，功\力盡被$N鎖住!!\n" + NOR,
        "dodge":   30,
        "parry":   30,
        "damage":   250,
        "force":    270,
        "damage_type" : "氣血逆行"
]),

([ "action" :HIM + "$N使出" + HIB + "『" + HIM + "天殘手" + HIB + "』" + HIM + "中的" + HIB + "『" + HIM + "分筋錯骨" + HIB + "』" + HIM + "，雙手一探，順勢一扭，一挫，$n嚎叫連連原來$n的筋脈已被錯開，手法之殘忍不禁令人毛骨悚然...\n" + NOR,
        "dodge":   30,
        "parry":    30,
        "damage":   250,
        "force":    290,
        "damage_type" : "筋脈挫傷"
]),

([ "action" :HIM + "$N使出了" + HIB + "『" + HIM + "天殘一氣指" + HIB + "』" + HIM + "食指一伸一道凌厲的指力往$n的$l射出，四周生物被這到凌厲之氣所掃，非死即碎!!\n" + NOR,
        "dodge":    30,
        "parry":    30,
        "damage":   270,
        "force":    300,
        "damage_type" : "刺傷"
]),

([ "action" :HIM + "$N將全身真氣聚於胸前，聚氣凝功\，四周地面剎那間不斷震動，狂風大作，正是" + HIB + "『" + HIM + "天殘手" + HIB + "』" + HIM + "的超級絕招" + HIB + "『" + HIM + "天殘轟天擊" + HIB + "』" + HIM + "的前奏!!驀然$N一聲大喝，將所聚之真氣一次激出，狠狠地射向$n的胸口!!\n" + NOR,
        "dodge":   100,
        "parry":   100,
        "damage":   240,
        "force":    270,
        "post_action":  (:super:),
        "damage_type" : "炸傷"
]),


});


void super(object me, object victim, object  weapon, int damage)
{
  message_vision(HIR + "結果$N所凝的真氣在$n的胸口瘋狂炸開，血花四濺，令人觸目心驚!!\n" + NOR,me,victim);
  victim->receive_damage("kee",190,me);
  COMBAT_D->report_status(victim);
}
int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}


mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
    return parry_msg[random(sizeof(parry_msg))];
}
