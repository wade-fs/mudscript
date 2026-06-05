//修羅心法

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }
  
int practice_skill(object me)
{
        return notify_fail("修羅心法只能從運用(exert)中增加熟練度。\n");
}

void skill_improved(object me)

{
        int s;

        tell_object(me, HIW + "你頭上冒起一股" + HIM + "綠色" + HIW + "的冥殿氣勁,你的修羅心法又更進一層了!! \n" + NOR);
}
string exert_function_file(string act)
{

  return CLASS_D("common/") + act;
}

string perform_action_file( string func)
{
   return PERFORM_D("fiendforce/") + func;
}



