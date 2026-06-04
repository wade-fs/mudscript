#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
      if(me->query("mark/love")!=1)  return notify_fail("練情傾七式需經高人指點。\n");
      else return 1;
}

int practice_skill(object me)
{
        return notify_fail("情傾七式只能從運用(exert)中增加熟練度。\n");
}
void skill_improved(object me)
{
        tell_object(me,HIW + "一陣冰箔籠罩你的全身，你的情傾七式更加熟練了!! \n" + NOR);

}
string exert_function_file(string act)
{
 return CLASS_D("poisoner") +"/loveforce/"+act; 
}

string perform_action_file( string func)
{
   return CLASS_D("poisoner") + "/loveforce/"+func;
}

