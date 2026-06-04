#include <ansi.h>
inherit SKILL;
//$n->me  $N->enemy
string *dodge_msg = ({

"\n$n原地一躍，使出了" + HIW + "『" + HIC + "乞食漫舞" + HIW + "』" + NOR + "的撐扞跳，跳得飛高，輕易躲過了$N的攻擊。\n",

"\n$n見岌岌可危，連忙施展了步伐中的" + HIW + "『" + HIY + "物幻星移" + HIW + "』" + NOR + "，把$N騙得團團轉。\n",

"\n$N向$n猛撲，但$n仍不慌不忙地閃了開來，一招" + HIW + "『" + HIB + "移形換物" + HIW + "』" + NOR + "，使$N落了個空。\n",

"\n$n身形一轉，踏起" + HIW + "『" + HIC + "乞食漫舞" + HIW + "』" + NOR + "，猶如靈蛇般地快速來到$N身後，嚇得$N一時不知所措。\n",

"\n$n幻化為" + HIW + "『" + HIM + "數千身影" + HIW + "』" + NOR + "，將$N給團團圍住，接著便是給了$N一頓痛擊。\n",

"\n$n使出" + HIW + "『" + HIC + "乞食漫舞" + HIW + "』" + NOR + "之" + HIY + "星光點點" + NOR + "，萬燭般地亮光，刺的$N一時張不開眼睛，讓$n逃過攻擊。\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge")||(usage=="move");
}

int valid_learn(object me)
{
                return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if(me->query("family/family_name") != "丐幫")
                return notify_fail("你非丐幫子弟，不准習得此步法！\n");
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練步影迷蹤。\n");
        me->receive_wound("kee",5);
                return 1;
}

