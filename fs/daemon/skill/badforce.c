// badforce.c by ice
// modify by oda

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if( (int)me->query("bellicosity") < 10 )
		return notify_fail("你的殺氣不夠﹐無法領悟惡化魔功\。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("惡化魔功\只能用學的﹐或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("bandit") + "/badforce/" + func;
}

void skill_improved(object me)
{
	int s;

	tell_object(me, HIW "一股邪氣自你頭上冒出，你的惡化魔功\更加惡毒了!! \n" NOR);
	s = me->query_skill("badforce", 1);
	if( s%10==9 && random(s)>(int)me->query("max_force")/30) {
		tell_object(me, HIW "有鑑於你行惡有功\，你體內的邪惡力量被激發出來了。\n" NOR);
		me->add("max_force", random((int)s/30)+1);
	}
}
