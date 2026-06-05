// mogi npc skill 之 銀封劍法
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N手中$w銀光一閃使出一式" + HIW + "『陽炎獨煉』" + NOR + "，$w劃破空氣泛出陣陣火光，猶似地獄之火向$n折曲撕旋而去",
		"dodge":        -40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
                "damage_type" : "刺傷"
	]),
	([	"action":		"$N一式" + HIW + "『疾步雙飛』" + NOR + "，身形瞬如旋風亂落，殘影離散，銀光粼粼，無數的劍影直刺$n",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
                "damage_type" : "刺傷"	
	]),
	([	"action":		"$N氣息瞬變化柔為剛，使出銀封劍法中的" + HIW + "『碎岩十歎』" + NOR + "，劍壓一沉，挾天崩地裂之勢直迫$n",
		"dodge":	-40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
                "damage_type" : "刺傷"	
	]),
	([	"action":		"$N踮步飛躍直落$n的正上方，銀封劍法中的一式" + HIW + "『侵水百斷』" + NOR + "的劍氣封死了$n的生路，直指向$n的腦門刺去",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
                "damage_type" : "割傷"		
	]),
        ([      "action":              "$N劃劍為圓，以圓為界，一式" + HIW + "『葉華千舞』" + NOR + "逼出了連鎖劍氣，結界無限擴大，$n眼見已無所遁逃",
                "dodge":        -25,
                "damage":       250,
                "force":        250,
                "parry":        -10,
                "damage_type" : "割傷"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

