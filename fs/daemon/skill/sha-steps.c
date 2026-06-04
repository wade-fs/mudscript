// sha-steps.c by Roger 5/24/98
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"\n但是$n使出飛仙御劍步中的" + HIW + "「翦雲身法」" + NOR + "，輕飄飄地早已退在幾步之外\n",
"\n$n使出了飛仙御劍步中的" + HIR + "『御劍亂訣』" + NOR + "，身影殘幻，使$N的攻擊招式全部落空\n",
"\n$n使出" + HIB + "『倒踩七星步』" + NOR + "往後連退數步使$N的攻擊全部落空，連$n的衣服都沒沾到\n",
"\n$n使出了絕頂的" + HIG + "『御劍草上飛』" + NOR + "，輕巧地避過了$N的這記殺招\n",
"\n但$n使出" + HIC + "『踏水無痕』" + NOR + "輕功\，毫無困難地閃過了這招\n",
"\n但$n使出" + HIM + "『過眼身煙』" + NOR + "身法，使$N只攻擊到$n殘留的幻影\n",
});

int valid_skill_usage(string usage)
{
	return (usage=="dodge") || (usage=="move");
}
 int valid_enable(string usage)
 {
        return( usage=="dodge" || usage=="move") ;
 }

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 10 )
		return notify_fail("你的內力不夠﹐沒有辦法練飛仙御劍步 .\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 20
	||	(int)me->query("force") < 5 )
		return notify_fail("你的氣或內力不夠﹐不能練飛仙御劍步 .\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
