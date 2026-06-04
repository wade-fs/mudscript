#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bite(object me, object victim,object weapon, int damage);
void bite2(object me, object victim,object weapon, int damage);

mapping *action = ({
        ([      "action":               "$N撲了上來，以極快速的動作張嘴往$n的$l狠狠地一咬!!",
                "force":                 500,
                "damage":                500,
		"post_action":                (: bite :),
                "damage_type":  "咬傷"
        ]),
        ([      "action":               "$N撲了上來，以極其巧妙的動作張開了$N的大嘴瘋狂地往$n的$l狠狠地一咬!!",
                "force":                 500,
                "damage":                500,
		"post_action":                (: bite2 :),
                "damage_type":  "咬傷"
        ]),
});

void bite(object me, object victim,object weapon, int damage)
{
        message_vision(HIR + "$N張開大口猛咬一口, 在$n的身上狠狠的咬了一塊肉下來!!\n" + NOR,me,victim);
	victim->receive_wound("kee",3000);
	COMBAT_D->report_status(victim);
}

void bite2(object me, object victim,object weapon, int damage)
{
        message_vision(HIR + "$N張開大口猛咬一口, 在$n的身上狠狠的咬了一塊肉下來!!\n" + NOR,me,victim);
	victim->receive_wound("kee",3000);
	COMBAT_D->report_status(victim);
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
