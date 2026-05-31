//金風細雨樓skill 之 風訣鎚法
//這是金風細雨樓一般護衛的skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N狂舞$w使出一式『風迫蒼崗』，迫起雷風轟隆，風壓逼得$n動彈不得，$w直直往$n$l揮去"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "鎚傷"
	]),
	([	"action":		"$N渾力朝地一鎚，一式『風碎氤氳』激起碎石奔旋，風壓急變蛇竄從四面八方捲向$n"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "骨折"	
	]),
	([	"action":		"$N揮鎚如雙臂直搗$n懷裡，使出了一式『風煌鐘煙』，似虛若幻化剛為柔地拍向$n身上各要穴"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "內傷"	
	]),
	([	"action":		"$N飛步欠身低竄，一式『風咬轟揚』捲舞碎砂揚塵，破風聲如天崩地裂，挾萬鈞之勢擊向$n"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "骨折"		
	]),
        ([      "action":              "$N一式『風掃天魃』手裡$w再次激起狂風呼嘯，彷彿旋龍昇天風虎長鳴直追$n的六大要處"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "鎚傷"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

