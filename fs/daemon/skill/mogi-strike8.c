// mogi npc skill 之 太陰虛幻寶鑑
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string *parry_msg= ({
   "$n雙手往上一翻, 雙腳蹲了個馬步, 使出一招「妖魔聚鼎」, 將妖氣凝聚於全身上下, 硬生生的把$N的招式接了下來!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖攔路」, 三指由中宮飛快的探向$n的咽喉, 破解了$N的攻勢。\n",
});

mapping *action = ({
([ "action" : HIC"$N身影翩翩使出太陰虛幻寶鑑中的一式"HIY"『蝶舞花山』"HIC"，如風搖塵飄忽不定地接近$n，出奇不意地點向$n$l\n"NOR,
        "dodge":   20,
        "parry":   20,
        "damage":  250,
        "force":   290,        
        "damage_type" : "刺傷"
        
]),

([ "action" :HIC"$N雙足輕踮使出一式"HIY"『雀舞稻香』"HIC"猶如雀鳥點躍，輕盈而迅速地向$n$l點去"NOR,
        "dodge":   30,
        "parry":   30,
        "damage":   250,
        "force":    270,
        
        "damage_type" : "刺傷"
]),

([ "action" :HIC"$N飛如輕風流盪迴旋，一式"HIY"『鳳舞瑤池』"HIC"漫天飛舞盤繞，以幻為真以虛為實地劃向$n\n"NOR,
        "dodge":   30,
        "parry":    30,
        "damage":   250,
        "force":    290,
        "damage_type" : "割傷"
]),

([ "action" :HIC"$N飛身翻躍使出太陰虛幻寶鑑中的一式"HIY"『龍舞雲端』"HIC"，在眨眼間轉柔為剛聚力於指，筆直朝$n$l刺去\n"NOR,
        "dodge":    30,
        "parry":    30,
        "damage":   270,
        "force":    300,
        "damage_type" : "刺傷"
]),

([ "action" :HIC"$N倩影盡散，魅光氤氳，一式"HIY"『魅舞月下』"HIC"化出妖影萬千，彷彿群魔掙血群群圍向$n\n"NOR,
        "dodge":   100,
        "parry":   100,
        "damage":  240,
        "force":   270,
        
        "damage_type" : "陰傷"
]),

([ "action" :HIC"$N一式"HIY"『女舞穹蒼』"HIC"在舉手投足之間散著陣陣香氣，如仙女迴夜遊魂走塵，若隱若現地刺向$n心窩\n"NOR,
        "dodge":   100,
        "parry":   100,
        "damage":  240,
        "force":   270,       
        "damage_type" : "陰傷"
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
