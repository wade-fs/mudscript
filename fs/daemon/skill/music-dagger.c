// 金風細雨樓skill 之 今音匕法
//第二樓樓主花憶妍武功
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		HIW + "$N迴袖舞裙使出一式" + HIG + "『春吟牡丹』" + HIW + "，匕尖在空氣中紋出的華光猶如牡丹的花瓣越舞越是逼近$n" + NOR,
		"damage":	190,
                "force":        190,
                "damage_type" : "刺傷"
	]),
	([	"action":		HIW + "$N一式" + HIM + "『鵲鳴杜鵑』" + HIW + "欺身下壓，卻在一瞬間仰滑而揚避開了$n的攻勢繞到$n身後，一個肘頂打向$n的後心窩，同時匕尖也刺向$n$l" + NOR,
		"damage":	190,
                "force":        190,
                "damage_type" : "刺傷"	
	]),
	([	"action":		HIW + "$N輕點落地盈巧若蜓，一式" + HIB + "『蜓唱水仙』" + HIW + "在$n身周不停迴繞玩弄$n在股掌之間，出奇不意的往$n胸口刺去" + NOR,
		"damage":	190,
                "force":        190,
                "damage_type" : "刺傷"	
	]),
	([	"action":		HIW + "$N踮步飛繞使出一式" + HIM + "『蝶詠百合』" + HIW + "，彷彿幻化成一隻蝴蝶在空氣中飄旋，在$n神暈目眩之際，手上的$w" + HIW + "已竄進$n懷裡" + NOR,
		"damage":	190,
                "force":        190,
                "damage_type" : "刺傷"		
	]),
        ([      "action":              HIW + "$N突若亂雨走若奔塵使出了" + HIY + "『蜂歌薔薇』" + HIW + "，匕尖在空氣裡閃出殘影幢幢，從四面八方激烈的突向$n" + NOR,
		"damage":	190,
                "force":        190,
                "damage_type" : "刺傷"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

