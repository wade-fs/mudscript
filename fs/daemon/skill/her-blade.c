// spring-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N手中$w騰出﹐使出一式「浩氣萬千」往$n$l劈去",
		"damage":		200,
	"dodge":		50,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N一招「氣若干雲」﹐手中$w如猛虎般往$n$l砍去",
		"damage":	150,
		"dodge":	-20,
		"parry":	40,
		"damage_type": "砍傷",
	]),
	([	"action":		"$N高舉手中$w﹐一招「萬夫莫敵」往$n$l劈去",
		"damage":	200,
		"dodge":	40,
		"parry":	30,
		"damage_type": "砍傷",
	]),
	([	"action":		"$N將手中$w一撩﹐一招「干戈玉帛」往$n$l砍去",
		"damge":	50,
		"dodge":	20,
		"parry":	10,
		"damage_type": "砍傷",
	]),
});

int valid_learn(object me)
{
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必須先找一把刀﹐才能練刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的體力不夠練這門刀法﹐還是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
