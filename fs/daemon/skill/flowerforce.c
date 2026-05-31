// follow-force by chan
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
        return notify_fail("蓮花心經只能用學的﹐或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("beggar") + "/followforce/" + func;
}
