// blood_force.c
// Swy QC 98/6/1
inherit SKILL;
inherit SSERVER;


int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }


int practice_skill(object me)
{
             return notify_fail("血魔心法只能用學的﹐或是從(exert)中獲的熟練度。\n");
}

string exert_function_file(string func)
{
return PERFORM_D("blood_force/")+func;
}

string perform_action_file(string func)
{
   return PERFORM_D("blood_force/")+func;
}
