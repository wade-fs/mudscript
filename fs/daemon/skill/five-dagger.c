// five-dagger.c  .........名字待真昨
// 五招就好..........:P

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bleed(object me, object victim, object weapon, int damage);
string *parry_msg=
    ({
   "$n將身體靠向$N, 一招『 沾衣十八跌 』, 將$N黏在原地, 使不開招式!\n",
   "$n把手中的$w舞成圓環, 一招『 雲迴圓月 』, 將$N的攻勢盡數擋了下來。\n",
   "$n以靜制動, 手中$w平舉胸前, 一招『 如封似閉 』, 化解了$N的攻勢!\n",
    });

//unarmed, dagger_action

mapping *action = ({
([ "action":"$N使出『 蘭花拂穴手 』,指尖微微前指,一道氣劍向$n射了去!\n",
        "dodge": -10,
        "parry": -20,
        "damage": 250,
        "force":  240,
        "damage_type":  "穴道受制",
]),

([ "action":"$N一招『 清風拂袖掌 』,雙手一揮,向$n掃了一道掌風!\n",
        "dodge": -20,
        "parry": -10,
        "damage": 260,
        "force": 230,
        "damage_type": "刺傷",
]),

([ "action" : "$N『秋風狂捲』,轉而一式『飛花落葉』,身體如飛花葉落,向$n撲了過去!\n",
        "dodge": -40,
        "parry": 10,
        "damage": 270,
        "force": 290,
        "damage_type": "掌傷",
]),

([ "action":"$N『雲霧漫漫』身法迷濛,進而一招『飛瀑長虹』,身軀向前一躍,打向$n!\n",
        "dodge": 20,
        "parry": -10,
        "damage": 290,
        "force": 280,
        "damage_type": "戳傷",
]),
([ "action" : "$N一招『絕淵逢生』,忽地一式『洞裡乾坤』,$n誤入$N的陷井!\n",
        "dodge": -20,
        "parry": 20,
        "damage": 300,
        "force": 280,
        "damage_type": "掌傷",
]),

//weapon_action

([ "action":"$N手持$w,一招『翠柏迎人』,緊跟一招『荊棘拒客』,向$n的雙臂連刺數回!\n",
        "dodge": -20,
        "parry": -10,
        "damage": 240,
        "force":  60,
        "damage_type":  "刺傷",
]),

([ "action":"$N把手中$w舞了開,『玄機暗藏』引誘$n上當,隨後一招『谷裡乾坤』刺向$n!\n",
        "dodge": 25,
        "parry": -10,
        "damage": 280,
        "force": 70,
        "damage_type": "刺傷",
]),
([ "action":"$N舞動$w一招『谷裡遇劫』疾向$n的咽喉刺去,而後身形往旁一縱『絕地逢生』快速地避開!\n",
        "dodge": -40,
        "parry": -20,
        "damage": 240,
        "force": 70,
        "damage_type": "刺傷",
]),
([ "action":"$N忽地面露喜色,雙手急捧,一式『神農遺經』向$n遞了過去,倏地$N雙手一張,大叫一聲『琉璃散暉』!\n",
        "dodge": 20,
        "parry": -20,
        "damage": 260,
        "force": 80,
        "damage_type": "刺傷",
]),
([ "action":"$N招式一轉,『古木蒼天』進而大叫一聲『蘭陵氣劍～～』,手中$w向$n任脈大穴射出七道真氣!\n ",
        "dodge": 20,
        "parry": -20,
        "damage": 300,
        "force": 90,
        "damage_type":"刺傷",
        "post_action": (: bleed :),
]),
});

//超強攻擊

void bleed(object me, object victim, object weapon, int damage)
{
        if(damage > 40)
         {
          victim->apply_condition("bleeding", random((int)damage / 10 +
          (int)me->query_skill("lan-dagger",1)/10));
          message_vision(sprintf("$N『 蘭陵氣劍 』刺透了$n身上的任脈大穴, $n的身上血斑點點。\n"),me,victim);
         }
}

mapping query_action(object me, object weapon)
{
        object wea=me->query_temp("weapon");
      if  (wea!=0)
            return action[random(5)+5];
      else
          return action[random(5)];
}

int valid_learn(object me)
{
        if(!me->query_temp("weapon"))
           tell_object(me,"沒有針怎麼練\n");
return 1;

        if(me->query_skill("cure")*1<=me->query_skill("seven-needle",1))
return notify_fail("你的醫療技能太差了吧! 怎麼拿刺人! 萬一割錯了很痛的呢! \n");
       return 1;
}

int valid_enable(string usage)
{
/*      object me=this_player();
      object wea=find_object(me->query_temp("weapon"));
         {
          if(wea!=1)
          if(wea->query("skill_type")=="dagger")
           {
            me->map_skill("dagger","seven-dagger");
            me->map_skill("parry","seven-dagger");
            me->map_skill("unarmed",0);
            return (usage=="dagger")||(usage=="parry");
           }
          me->map_skill("unarmed","seven-dagger");
          me->map_skill("dagger",0);
          me->map_skill("parry",0);
          return (usage=="unarmed");
         }     */
        return (usage=="dagger");
}

int practice_skill(object me)
{
        if(!me->query_temp("weapon") || !me->query_temp("secondary_weapon") )
          return notify_fail("練七奇炙針訣還是要拿根針吧!....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不夠﹐無法練習。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("體力不夠囉! 休息一下再繼續練吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前內力不足,休息一會兒再練吧.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}
