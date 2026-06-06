// shade-steps.c

inherit SKILL;

string *dodge_msg = ({
    "$n身影微動,已經藉一招「星光四散」繞到$N四周形成四個幻影。\n",
    "$n身形一轉使出「紅鸞星動」瞬時人離原位而避了開去,$N擊中了幻影。\n",
    "只見$n身影一晃即失,一式「流星趕月」已幻化在三丈之外。\n",
    "$n使出「斗轉星移」,$N之攻勢瞬間被化解,$n從容不迫地閃過。\n",
    "但$n使出一招「星隨氣轉」,身子隨$N攻擊之氣流輕輕飄了開去。\n",
    "$n身形微晃忽成七個幻影,$N困惑不已而攻擊失誤,正是一招「幻化七星」。\n",
     "$n人影忽滅,突見無數星芒環繞在$N周圍,使$N目瞪口呆,不知所措,這正是 幻星步 精華步法-「星羅棋布」。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if(me->query("kee") < 30 )
		return notify_fail("你的氣不夠﹐沒辦法練幻星步。\n");
	me->receive_damage("kee", 30);
	return 1;
}
