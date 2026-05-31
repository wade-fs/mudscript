// ghost-steps.c by oda

inherit SKILL;
#include <ansi.h>

string *dodge_msg=({
    "$n身子一軟，全身向後攤去，巧妙的躲過了$N的攻擊，正是幽冥身法中的"HIY"「氣游無定」"NOR"。\n",
    "$n使出幽冥身法中的"HIB"「虛幻無形」"NOR"，只見他身形一晃，$N擊中的只是殘像。\n",
    "只見$n身形一起，使出幽冥身法的絕技"HIM"「飄渺無蹤」"NOR"，無聲無息的飄到$N身後。\n",
    "只瞧$n的腳步急轉，身形一晃，使出的正是幽冥身法中的"HIG"「鬼影無從」"NOR"，整個人像空氣一般消失無蹤。\n",
    "$n的身子忽然一扭，整個人像鬼魂一般隨著$N的攻擊四處閃躲，用的正是幽冥身法中的"HIC"「魂隨無常」"NOR"。\n",
    "只見到$n腳步一墊，忽然出現好多個$n將$N團團包圍，正是幽冥身法中的"HIY"「殘化無尋」"NOR"，$N的攻擊處處落空。\n",
    "$n忽然將身形放慢，腳步隨風而動，身子隨心而轉，使出的正是幽冥身法的奧義絕招"HIB"「幽冥無神」"NOR"，游刃有餘的將$N的攻擊一一躲過。\n",
	});

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_enable(string  usage)
{
	return (usage=="dodge"||usage=="move");
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的神不夠，不能練幽冥身法。\n");
	me->receive_damage("sen", 30);
	return 1;
}
