// nine-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n身形一轉﹐連點數步﹐避了開去﹗\n",
	"$n使出陳家身法中的「蝶影步」閃開$N的攻擊﹗\n",
	"$n連踩十數步﹐身形連變﹐躲開$N這一招﹗\n",
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
	if((int)me->query("gin")<30)
		return notify_fail("你的精不夠﹐不能練陳家身法。\n");
	me->receive_damage("gin",30);
	return 1;
}
