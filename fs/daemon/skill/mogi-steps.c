// mogi npc dodge 之 劫夜走天步
//調整斷行問題 by blazakira 2011/7/24

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"$n飄散如霧，走地無跡使出一式" + HIM + "『幽影無蹤』" + NOR + "在被擊中的瞬間化實為虛，避開了$N的攻擊。\n",
"$n一式" + HIM + "『劫影無魂』" + NOR + "，身影如幽靈化幻，$N猛烈一擊卻只是打中了\n",
"$n踏天而行使出一式" + HIM + "『夜影無痕』" + NOR + "，化身為塵，如塵舞風，任$N怎麼攻也迫不進$n身周。\n",
"$n魔氣揮散使出一式" + HIM + "『魔影無滅』" + NOR + "，魔氣在$n身周形成一膜護身氣勁，滑過了$N的攻勢。\n",
"$n柳步輕移，身影搖曳生姿，使出了一式" + HIM + "『倩影無麗』" + NOR + "，閃出了些微的空間恰巧躲過$N的攻擊。\n",
});

int valid_skill_usage(string usage)
{
  return (usage=="dodge") || (usage=="move");
}

int valid_enable(string usage)
{
  return( usage=="dodge" || usage=="move") ;
}

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}
