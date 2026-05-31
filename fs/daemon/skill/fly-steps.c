//fly-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n使出一個「蜉蝣戲水」的身法 ,左腳一掃 ,倏地一個旋身 ,騰出一丈以外 !\n",
	"$n運起全身真力 ,一個「風捲落花」之勢 ,拔起三丈多高 !\n",
	"$n雙臂一振 ,便以「海燕掠波」之勢 ,「嘶」的掠風聲中 ,身形拔起三丈多高 .\n",
	"$n不慌不忙 ,長嘯一聲 ,一招「東風洗柳」 ,躍了開去 .\n",
});

int valid_enable(string usage) {
	return (usage=="dodge")||(usage=="move");
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
	if((int)me->query("kee")<30)
		return notify_fail("你的氣不夠﹐不能練飛雲縱。\n");
	me->receive_damage("kee",30);
	return 1;
}
string perform_action_file(string action)
{
	return CLASS_D("blademan")+ "/fly-steps/" +action;
}
