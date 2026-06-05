#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bomb(object me, object victim,object weapon, int damage);

mapping *action = ({
        ([      "action":               "$N向發了瘋似的往$n撲去!!",
                "force":                 500,
                "damage":                500,
		"post_action":                (: bomb :),
                "damage_type":  "撞傷"
        ]),
});

void bomb(object me, object victim,object weapon, int damage)
{
        message_vision(HIR + "\n$N抓住$n身體之後瞬間爆炸, 炸的連碎片都不剩!!\n" + NOR,me,victim);
        message_vision(HIR + "\n$N被炸的全身是傷, 嚇到一點殺意都沒了!!\n" + NOR,victim);
        me->move("/open/killer/outsea/trashroom.c");
	me->set("combat_exp",0);
	damage=victim->query("kee")*0.9;
	if (victim->query("kee") < 5000 || victim->query("gin") < 3000 || victim->query("sen") < 3000) 
	{
	COMBAT_D->report_status(victim);
	victim->die();
	victim->set("bellicosity", 0);	
	me->die();
	}
	if (victim->query("kee") > 5000 && victim->query("gin") > 3000 && victim->query("sen") > 3000)
	{ 
	victim->receive_wound("kee", damage);
	victim->receive_wound("gin", 3000);
	victim->receive_wound("sen", 3000);
	victim->set("bellicosity", 0);
	COMBAT_D->report_status(victim);
	me->die();
        }
}



int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}
