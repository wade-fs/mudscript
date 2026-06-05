//金風細雨樓skill 之 細訣匕法
//這是金風細雨樓一般護衛之skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N一式『細柳孔雀』蹲身撈上如雀衝翔，瞬滑而落反手再刃，又以極快的速度迴鋒向$n突進" + NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺傷"
	]),
	([	"action":		"$N將身子壓得極低向前急急踏步使出了『細桂朧泉』，直向$n下盤叩擊突進" + NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺傷"	
	]),
	([	"action":		"$N從側切入使出一式『細櫻天嶂』，$w如風亂櫻瓣勾裂著空氣朝$n連環切刺" + NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺傷"	
	]),
	([	"action":		"$N如碎杏隨風飄旋，翩然使出一式『細杏飄舞』，忽左忽右的上下飄動，瞬間以極快的速度向$n劃去" + NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺傷"		
	]),
        ([      "action":              "$N使出一式『細樹參周』，在往$n$l掃砍的當兒迴身再進，幾乎在同一時間又朝$n腦喉心腹四處突入" + NOR,
		"damage":	90,
                "force":        90,
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

