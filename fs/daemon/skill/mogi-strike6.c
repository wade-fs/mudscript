// mogi npc skill 之 龍羅刀法
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N使出一式"HIY"『逆鱗龍膽』"NOR"，毫無掩飾的殺氣如雷驟落，一列刀氣朝著$n狂捲而去",
		"dodge":        -40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
                "damage_type" : "砍傷"
	]),
	([	"action":		"$N一氣三化使出了一式"HIY"『龍爪崩山』"NOR"，在激出三道刀氣的同時，$N踱步前躍追著刀氣而去，往$n$l猛烈砍殺",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
                "damage_type" : "砍傷"	
	]),
	([	"action":		"$N拔身高躍追向$n，一式"HIY"『赤烈崩林』"NOR"捲起強烈的風壓，直逼$n追去",
		"dodge":	-40,
		"damage":	250,
                "force":        250,
		"parry":	-30,
                "damage_type" : "砍傷"	
	]),
	([	"action":		"$N飛身數丈欲採以高壓低之勢使出一式"HIY"『空天座架』"NOR"，魔之炎灼之氣如橫風縱雨筆直竄進$n懷裡",
		"dodge":	-30,
		"damage":	250,
                "force":        250,
		"parry":	-20,
                "damage_type" : "劈傷"		
	]),
        ([      "action":              "$N放出燄燄血氣，雙手反握$w窮全身之力使出一式"HIY"『霸襲龍尾』"NOR"，破天撼地的威力轟然迫近$n",
                "dodge":        -25,
                "damage":       250,
                "force":        250,
                "parry":        -10,
                "damage_type" : "劈傷"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

