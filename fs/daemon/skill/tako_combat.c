#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void slap(object me, object victim,object weapon, int damage);

mapping *action = ({
        ([      "action":               "八爪章魚撲了上來，伸出觸手狠狠的往$n的$l抽去!!",
                "force":                 500,
                "damage":                500,
		"post_action":                (: slap :),
                "damage_type":  "抽傷"
        ]),
        ([      "action":               "八爪章魚撲了上來，伸出觸手緊緊纏住$n的$l，似乎要將$n的$l扯下來!!",
                "force":                 500,
                "damage":                500,
		"post_action":                (: slap :),
                "damage_type":  "扯傷"
        ]),
});

void slap(object me, object victim,object weapon, int damage)
{
	if( victim->is_busy()&& me->query_temp("conti")!=1 )
	{
        message_vision(GRN + "\n$N" + GRN + "趁著$n動彈不得之際，迅速的發動八爪快攻!!\n" + NOR,me,victim);
        me->set_temp("conti",1);
	for(int k=0 ; k<7 ; k++)
	{
	COMBAT_D->do_attack(me, victim,me->query_temp("weapon"), TYPE_QUICK);
	}
	me->delete_temp("conti");
	victim->delete_busy();
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
