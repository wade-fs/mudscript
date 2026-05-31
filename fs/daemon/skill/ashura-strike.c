//修羅霸拳(Ashura-rike) Edit by del
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":       
"$N使出修羅霸拳第一式"HIR"『殺』"NOR"，腳下步伐越走越快，令$n無法捉摸，"
"只見$N的雙拳以迅雷不及掩耳的速度攻擊$n",
                "damage":80,
                "dodge":10,
                "damage_type": "瘀傷"
        ]),
        ([      "action":       
"$N暴吼一聲，將真氣灌注在拳頭，使出修羅霸拳第二式"HIB"『破』"NOR"，強猛"
"沈厚的拳勁以排山倒海之勢揮向$n的$l",
                "damage":80,
                "dodge":20,
                "damage_type": "瘀傷"
        ]),
        ([      "action":       
"$N暗運內勁，以手為刃，順勢使出修羅霸拳第三式"HIB"『滅』"NOR"，攻勢猶如"
"如水銀瀉地般從各個方向攻擊$n",
                "damage":100,
                "dodge":10,
                "damage_type": "內傷"
        ]),

        ([      "action":
"$N將修羅霸拳第四式"HIR"『絕』"NOR"引發的熊熊烈焰引到自己的雙拳之上，正"
"當$n錯愕之際，無窮的的攻勢已如迅雷疾風般攻擊$n",
                "damage":100,
                "dodge":10,
                "damage_type": "瘀傷"
        ]),

        ([      "action":
"$N將全身殺氣釋放，使出修羅霸拳第五式"HIR"『斷』"NOR"，內含無窮殺意的拳"
"勢就像一把鋒利的巨刃般要將$n攔腰斬斷",
                "damage" : 150,
                "dodge"  :  10,
                "damage_type" : "內傷"
        ]),

});

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

