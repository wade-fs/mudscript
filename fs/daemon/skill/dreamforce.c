// dreamforce.c

inherit SKILL;
inherit SSERVER;


int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }


int practice_skill(object me)
{
             return notify_fail("迴夢心經只能用學的﹐或是從(exert)中獲的熟練度。\n");
}


string exert_function_file(string func)
{
   return CLASS_D("dancer")+"/dreamforce/"+func;
}
        
