//tiger-steps.c by Dico
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"\n$n使出一招" + HIB + "「攀雲乘龍」" + NOR + "不見$n彎腿作勢，忽然全身拔起，
已竄到了天空，躲開了$N的攻擊，一個倒翻觔斗，又站在$N面前。\n",
"\n$n使出" + HIY + "「岳王神箭」" + NOR + "身子當真如箭離弦，急射而出，避開了$N的強烈攻勢。\n",
"\n$n一招" + HIR + "「金雁功\」" + NOR + "只見$n筆直的衝向天際，閃過$N的殺招。\n",
"\n$n腳步輕盈，身子轉折滑溜，直似游魚一般，從$N的身旁繞過，
轉守為攻，正是" + HIW + "神行百變" + NOR + "中的絕妙高招-" + HIG + "「移行換位」" + NOR + "。\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

