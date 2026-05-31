// celestrike.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void at_head(object me, object victim, object  weapon, int damage);
void at_foot(object me, object victim, object  weapon, int damage);

mapping *action = ({
	([	"action":		"$N使出一招"HIY"「大天羅式」"NOR"﹐右掌穿出擊向$n的$l",
		"dodge":		-130,
		"parry":		150,
		"force":		400,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出一招"HIY"「大天羅式」"NOR"﹐左掌化虛為實擊向$n的$l",
		"dodge":		-110,
		"parry":		-230,
		"force":		420,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出天邪掌法"HIY"「小天羅式」"NOR"﹐如鬼魅般欺至$n身前﹐一掌拍向$n的$l",
		"dodge":		-130,
		"parry":		210,
		"force":		430,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N雙掌一錯﹐使出"HIY"「雪陽三連月」"NOR"﹐對準$n的$l連續拍出三掌",
		"dodge":		110,
		"parry":		-230,
		"force":		440,
                "post_action":               (: at_head :),
 		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N左掌畫了個圈圈﹐右掌推出﹐一招"HIY"「靈動五方鼓」"NOR"擊向$n$l",
		"dodge":		-120,
		"parry":		-230,
		"force":		450,
                "post_action":               (: at_head :),
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N使出"HIY"「風雷七星斷」"NOR"﹐身形散作七處同時向$n的$l出掌攻擊",
		"dodge":		-170,
		"parry":		-210,
		"force":		460,
                "post_action":               (: at_foot :),
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N吐氣揚聲﹐一招"HIY"「氣撼九重天」"NOR"雙掌併力推出",
		"parry":		-240,
		"force":		500,
                "post_action":               (: at_foot :),
		"damage_type":	"瘀傷"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("練天邪神掌必須空手。\n");
	if( (int)me->query_skill("celestial", 1) < 20 )
		return notify_fail("你的天邪神功\火候不足﹐無法練天邪掌法。\n");
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的內力太弱﹐無法練天邪掌法。\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
	if( (int)me->query("force") < 5 )
		return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	return 1;
}
void at_head(object me, object victim, object  weapon, int damage)
{
   int sp_value;
   sp_value =300+random(300);
   victim->receive_damage("kee",sp_value,me);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
void at_foot(object me, object victim, object  weapon, int damage)
{
   int sp_value;
   sp_value =300+random(300);
   victim->receive_damage("kee",sp_value,me);
   victim->start_busy(1);
   COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}
