inherit SKILL;

mapping *action = ({
        ([      "action":               "$N撲上來張嘴往$n的$l狠狠地一咬!!",
                "dodge":                  70,
                "parry":                 200,
                "force":                 170,
                "damage":                170,
                "damage_type":  "咬傷"
        ]),
        ([      "action":               "$N撲上來張開了$N的大嘴瘋狂地往$n的$l狠狠地一咬!!",
                "dodge":                  70,
                "parry":                 200,
                "force":                 230,
                "damage":                230,
                "damage_type":  "咬傷"
        ]),
        ([      "action":               "$N撲上來用$N的前腳往$n的$l用力地一抓!!",
                "dodge":                  70,
                "parry":                 200,
                "force":                 300,
                "damage":                300,
                "damage_type":  "抓傷"
        ]),
        ([      "action":               "$N撲上來用$N強而有力的腳往$n的$l狠狠地一踢!!",
                "dodge":                  70,
                "parry":                 200,
                "force":                 350,
                "damage":                350,
                "damage_type":  "踢傷"
        ]),
});

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
