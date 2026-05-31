inherit SKILL;
#include <ansi.h>
#include <combat.h>

mapping *action =
({
//1
        ([
"action" : 
        "$N$w伸出，一招「撥狗朝天」，將杖身挑著$n的身子甩了上來！杖頭直翻起來，砸向$n額角！",
                "damage" : 200,
                "force" : 50,
                "damage_type" : "擊傷",
        ]),
//2
    ([
        "action" :
        "$N哼的一聲，一式「棒打雙獒」使了出來，身影仿彿幻化成兩個，以迅雷之勢，雙雙擊向了$n的破綻，使$n左滯右肘！",
                "damage" : 200,
                "force" : 80,
                "damage_type" : "擊傷",
        ]),
//3
    ([
        "action" :
        "$N持$w使了一記「人狗爭食」，忽地翻身一滾$w伸處，向$n腰間挑去！",
                "damage" : 250,
                "force" : 120,
                "damage_type" : "擊傷",
        ]),
//4
    ([
        "action" :
        "$N在這險象環生之際，隻手舉$w朝天揮出「倚杖喝狗」，棍中夾經硬捶$n後心！",
                "damage" : 200,
                "force" : 100,
                "damage_type" : "擊傷",
        ]),

});

int valid_enable(string usage)
{
        return usage=="staff"||usage=="parry";
}


mapping query_action(object me, object weapon)
{
/*      int level,force_level;
//此部份為隨機出招部份
    level =(int)me->query_skill("follow-staff",1);
    force_level=(int)me->query_skill("followforce",1);    
    if(level > 0  && level < 50 )
        return action[random(5)];
    if(level >= 50  && level < 100 )
        return action[random(7)];
    if(level >= 100  && level < 130 )
        return action[random(8)];
    if(level >= 130 && level < 150 )
        return action[random(10)];
    if(level >= 150 && level < 180 )
        return action[random(15)];
        if(level >=180 && force_level >= 200)
                return action[random(21)];*/
     return action[random(sizeof(action))];
}
        


