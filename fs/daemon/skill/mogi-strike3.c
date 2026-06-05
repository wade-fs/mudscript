// mogi npc skill 之 髮天殺


#include <ansi.h>
#include <combat.h>
inherit SKILL;
string *parry_msg= ({
   "$n雙手往上一翻, 雙腳蹲了個馬步, 使出一招「妖魔聚鼎」, 將妖氣凝聚於全身上下, 硬生生的把$N的招式接了下來!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖攔路」, 三指由中宮飛快的探向$n的咽喉, 破解了$N的攻勢。\n",
});

mapping *action = ({
([ "action" : "$N揚首側頭使出一招" + HIG + "『彩女織天』" + NOR + "，瞬間飛髮插天宛若群龍翻舞，圍殺$n的腦穴\n" + NOR,
        "dodge":   20,
        "parry":   20,
        "damage":  250,
        "force":   290,        
        "damage_type" : "鞭傷"
        
]),

([ "action" :"$N飛身翻躍，在閃過$n攻擊的剎那使出了一式" + HIG + "『蜘女羅地』" + NOR + "，只見漫天飛髮如蛛網一般斷了$n的生路，直竄$n的頸喉\n" + NOR,
        "dodge":   30,
        "parry":   30,
        "damage":   250,
        "force":    270,
        
        "damage_type" : "鞭傷"
]),

([ "action" :"$N後躍輕迴半身，髮絲如妖蛇亂竄，一式" + HIG + "『蠶女紡衣』" + NOR + "渾然而生，髮絲毫無規則的奔向$n的心窩\n" + NOR,
        "dodge":   30,
        "parry":    30,
        "damage":   250,
        "force":    290,
        "damage_type" : "鞭傷"
]),

([ "action" :"$N身形一躬昂首一甩使出一式" + HIG + "『水女浣紗』" + NOR + "，頓時飛髮如瀑如流，忽剛忽柔，直搗$n的腹部要穴\n" + NOR,
        "dodge":    30,
        "parry":    30,
        "damage":   270,
        "force":    300,
        "damage_type" : "刺傷"
]),

([ "action" :"$N側頭左右一放使出一式" + HIG + "『淚\女網夢』" + NOR + "，髮絲飛奔流竄，從四面八方網向$n\n" + NOR,
        "dodge":   100,
        "parry":   100,
        "damage":  240,
        "force":   270,
        
        "damage_type" : "鞭傷"
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
