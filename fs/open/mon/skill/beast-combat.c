#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bite(object me, object victim,object weapon, int damage);
void bite2(object me, object victim,object weapon, int damage);
void claw(object me, object victim,object weapon, int damage);
void kick(object me, object victim,object weapon, int damage);

mapping *action = ({
        ([      "action":               "$N撲了上來，以極快速的動作張嘴往$n的$l狠狠地一咬!!",
                "dodge":                  80,
                "parry":                -200,
                "force":                 250,
                "damage":                250,
		"post_action":                (: bite :),
                "damage_type":  "咬傷"
        ]),
        ([      "action":               "$N撲了上來，以極其巧妙的動作張開了$N的大嘴瘋狂地往$n的$l狠狠地一咬!!",
                "dodge":                  80,
                "parry":                -200,
                "force":                 350,
                "damage":                350,
		"post_action":                (: bite2 :),
                "damage_type":  "咬傷"
        ]),
        ([      "action":               "$N撲了上來，用$N的前腳往$n的$l用力地一抓!!",
                "dodge":                  80,
                "parry":                -200,
                "force":                 400,
                "damage":                400,
		"post_action":                (: claw :),
                "damage_type":  "抓傷"
        ]),
        ([      "action":               "$N撲了上來，用$N強而有力的腳往$n的$l狠狠地一踢!!",
                "dodge":                  80,
                "parry":                -200,
                "force":                 500,
                "damage":                500,
		"post_action":                (: kick :),
                "damage_type":  "踢傷"
        ]),
});

void bite(object me, object victim,object weapon, int damage)
{
	if( random(2) == 1 )
	{
        message_vision(GRN + "$N" + GRN + "再大力一咬，在$n" + GRN + "身上咬出了一個很大的齒痕!!\n" + NOR,me,victim);
	victim->receive_wound("kee", random(300)+150,me);
	victim->receive_wound("gin", random(50)+25,me);
	victim->receive_wound("sen", random(50)+25,me);
	COMBAT_D->report_status(victim);
	}
}

void bite2(object me, object victim,object weapon, int damage)
{
	if( random(2) == 1 )
	{
        message_vision(RED + "$N" + RED + "狠狠用力的一咬，在$n" + RED + "身上咬出了一個奇大無比的齒痕!!\n" + NOR,me,victim);
	victim->receive_wound("kee", random(500)+250,me);
	victim->receive_wound("gin", random(100)+50,me);
	victim->receive_wound("sen", random(100)+50,me);
	COMBAT_D->report_status(victim);
	}
}

void claw(object me, object victim,object weapon, int damage)
{
	if( random(2) == 1 )
	{
        message_vision(YEL + "$N" + YEL + "朝$n" + YEL + "身上狠狠用力一抓，抓出了數條泛紅的血爪痕!!\n" + NOR,me,victim);
	victim->receive_wound("kee", random(700)+350,me);
	victim->receive_wound("gin", random(150)+75,me);
	victim->receive_wound("sen", random(150)+75,me);
	COMBAT_D->report_status(victim);
	}
}

void kick(object me, object victim,object weapon, int damage)
{
	if( random(2) == 1 )
	{
        message_vision(CYN + "$N" + CYN + "大力往$n" + CYN + "身上一踢，將$n" + CYN + "踢出個老遠，痛的$n" + CYN + "哭天搶地的!!\n" + NOR,me,victim);
	victim->receive_wound("kee", random(900)+450,me);
	victim->receive_wound("gin", random(200)+100,me);
	victim->receive_wound("sen", random(200)+100,me);
	COMBAT_D->report_status(victim);
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
