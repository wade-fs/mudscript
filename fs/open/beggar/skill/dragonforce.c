// dragonforce by chan
#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
        return notify_fail("降龍心法只能用學的﹐或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("beggar") + "/dragonforce/" + func;
}

void skill_improved(object me)
{
        int s;
        tell_object(me, HIW + "你的臉色由青變紅、紅變青降龍心法的修為更進一步了。\n" + NOR);
        s = me->query_skill("badforce", 1);
        if( s%10==9 && random(s)>(int)me->query("max_force")/30) {
                tell_object(me, HIW + "一股降龍內勁從丹田發出散入全身，使你的內功修為提高了。\n" + NOR);
                me->add("max_force", random((int)s/30)+1);
        }
}
