// mogi npc skill 之 葬列剖墳手


#include <ansi.h>
#include <combat.h>
inherit SKILL;

void blood1(object me, object  weapon);
void blood2(object me, object  weapon);
void blood3(object me, object  weapon);
void blood4(object me, object  weapon);
void blood5(object me, object  weapon);

string *parry_msg= ({
   "$n雙手往上一翻, 雙腳蹲了個馬步, 使出一招「妖魔聚鼎」, 將妖氣凝聚於全身上下, 硬生生的把$N的招式接了下來!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖攔路」, 三指由中宮飛快的探向$n的咽喉, 破解了$N的攻勢。\n",
});

mapping *action = ({
([ "action" : HIB + "$N身上魔氤滿溢陰氳陣陣，頓時黑光閃閃，一式葬列剖墳手中的" + HIM + "『剖墳舔屍』" + HIB + "挾著厚重的毒氣襲向$n的腦門\n" + NOR,
        "dodge":   20,
        "parry":   20,
        "damage":   180,
        "force":    150,
        "post_action":  (:blood1:),        
        "damage_type" : "毒傷"
        
]),

([ "action" :HIB + "$N使出一式" + HIM + "『送葬哀歌』" + HIB + "激出魔風陣陣，呼嘯之聲悲慟惱人，侵人心神，就在$n失魂之際，$N一掌打向$n\n" + NOR,
        "dodge":   30,
        "parry":   30,
        "damage":   180,
        "force":    150,
        "post_action":  (:blood2:),
        "damage_type" : "毒傷"
]),

([ "action" :HIB + "$N壓身直奔$n，就在$n欲發招之際的瞬間高高躍起，使出葬列剖墳手中的一式" + HIM + "『鴉佇髏\眼』" + HIB + "同時向$n的雙眼及喉間連發掌氣\n" + NOR,
        "dodge":   30,
        "parry":    30,
        "damage":   180,
        "force":    150,
        "post_action":  (:blood3:),
        "damage_type" : "毒傷"
]),

([ "action" :HIB + "$N雙掌一拍，煞時寒光眩目，一式" + HIM + "『屍淚\白燭』" + HIB + "連續擊出五道掌氣，直搗$n的腦喉心胸腹五大死穴\n" + NOR,
        "dodge":    30,
        "parry":    30,
        "damage":   180,
        "force":    150,
        "post_action":  (:blood4:),
        "damage_type" : "毒傷"
]),

([ "action" :HIB + "$N魔氣驟發，以指為掌，使出葬列剖墳手中的一式" + HIM + "『血骨殘肉』" + HIB + "，掌氣利如刀鋒旋裂直逼$n\n" + NOR,
        "dodge":   100,
        "parry":   100,
        "damage":   180,
        "force":    150,
        "post_action":  (:blood5:),
        "damage_type" : "毒傷"
]),


});

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

void blood1(object me,  object  weapon)
{
  int i,dark_poison;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 dark_poison=victim->query_condition("dark_poison");
 victim->apply_condition("dark_poison",5+dark_poison);
}
void blood2(object me, object  weapon)
{
 int i,fire_poison;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 fire_poison=victim->query_condition("fire_poison");
 victim->apply_condition("fire_poison",2+fire_poison);
}
void blood3(object me, object  weapon)
{
  int i,five_poison;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 five_poison=victim->query_condition("five_poison");
 victim->apply_condition("five_poison",5+five_poison);
}
void blood4(object me, object  weapon)
{
  int i,rose_poison;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 rose_poison=victim->query_condition("rose_poison");
 victim->apply_condition("rose_poison",5+rose_poison);
}
void blood5(object me, object  weapon)
{
   int i,snake_poison;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 snake_poison=victim->query_condition("snake_poison");
 victim->apply_condition("snake_poison",5+snake_poison);
}
