// fire-catch.c
#include <combat.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([      "action":               "$N使出聖火奇功\『絆』字訣，手中$w迅速狂掃向$n下盤﹗",
                "damage":               50,
                "force":            50,
	    "dodge":		-40,
	    "parry":		-40,
	    "damage_type":	"撞傷"
	]),
        ([      "action":               "$N使出聖火奇功\『劈』字訣，手中$w從空往下狠劈向$n的$l﹗",
                "damage":               70,
                "force":            70,
	    "dodge":		-50,
                "parry":                    -50,
	    "damage_type":	"鎚傷"
	]),
        ([      "action":               "$N轉動手中$w，霎時『轉』字訣隨棍而出閃電般擊向$n的$l﹗",
                "damage":               90,
                "force":            90,
	    "dodge":		-35,
	    "parry":		-35,
	    "damage_type":	"擊傷"
	]),
        ([      "action":               "$N揮動$w使出聖火奇功\『封』字訣，霎時一陣棍雨飛擊$n的$l﹗",
                 "damage":               100,
	                "force":            100,
     "dodge":		-30,
	     "parry":		-30,
	     "damage_type":	"擊傷"
        ]),
        ([      "action":               "$N突然身影晃動，使出『挑』字訣，手中$w由下往上抖向$n的$l﹗",
                "damage":               110,
                "force":            110,
                "dodge":                -30,
                "parry":                 -30,
                "damage_type":  "鎚傷"
        ]),
        ([      "action":               "$N使出『戳』字訣，只見手中$w化成團碧影，棍雨猛戳向$n的$l﹗",
                "damage":               120,
                "force":            120,
                "dodge":                -25,
                "parry":                  -25,
	    "damage_type":	"撞傷"
        ]),
        ([      "action":               "$N握住$w，使出『引』字訣，棍隨$n的攻擊順而點往$n的$l﹗",
                "force":            150,
                "damage":               150,
                "dodge":                -20,
                "parry":                  -20,
	    "damage_type":	"撞傷"
        ]),
        ([      "action":               "$N舞動$w使出『纏』字訣，迅速使出一陣棍網猛擊$n的$l﹗",
                "damage":              180,
                "force":            180,
                "dodge":                -20,
                "parry":                  -20,
                "damage_type":  "擊傷"
        ]),
        ([      "action":               "$N手中$w一舉，使出了『怒火九重天』綿延不斷的使出攻向$n的$l",
                "damage":              200,
                "force":            200,
                "dodge":                -10,
                "parry":                  -10,
                "damage_type":  "擊傷"
        ]),
});

int valid_learn(object me)
{
	if((int)me->query_str() + (int)me->query("max_force") / 5 <50)
		return notify_fail("你的膂力還不夠﹐也許\該練一練內力來增強力量。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="stick") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level=(int)me->query_skill("fire-catch", 1);
        limit=(int)skill_level/10;
        if (limit < 10)
                return action[random(limit)];
        else
                return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;
	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "stick" )
                return notify_fail("你必須使用聖火教的令牌或是〔聖火令〕﹐才能使用聖火奇功\。\n");
	if(me->query_skill("force")*3<=me->query_skill("fire-catch",1))
          return notify_fail("你的內力根基不夠, 不能用練聖火奇功\了。\n");
	if(me->query_skill("literate")*2<=me->query_skill("fire-catch",1))
          return notify_fail("你的知識不足﹐無法解讀聖火令上的奇妙武學。\n");
	return 1;
	if( (int)me->query("kee") < 60 )
                return notify_fail("你的體力不夠練〔聖火奇功\〕﹐還是先休息休息吧。\n");
	me->receive_damage("kee", 60);
	return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("prayer")+"/fire-catch/"+action;
}
