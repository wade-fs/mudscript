inherit SKILL;
#include <ansi.h>

int valid_enable(string usage) { return usage=="force" ; }

int practice_skill(object me)
{
        return notify_fail("養狗經自己練習是沒效果的！\n");
}

string exert_function_file(string func)
{

        return CLASS_D("beggar") + "/pkdog-force/" + func;
}

void skill_improved(object me)
{
        int i=me->query_skill("pkdog-force",1);
        tell_object(me,HIC + "你的養狗經更上了一層，你感到似乎可以號召更多狗兒！\n" + NOR);
    if (i%10==9 && me->query("max_force") > 2000)
        {
                tell_object(me,HIR + "經過幾番修練，你把深厚內力化為氣勁，吐納甚為自在！\n" + NOR);
                me->add("max_kee",50);
        }
}

