//魔界解quest 學的 skill
//焚天魔王極火功

//by roger

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{      
      if(me->query("quest/gold-fire")!=1)  return notify_fail("學極火功\要配合極火金身心法。\n");
      else return 1;
}

int practice_skill(object me)
{
	return notify_fail("極火功\只能從運用(exert)中增加熟練度。\n");
}

void skill_improved(object me)
{	
	tell_object(me, "一股火勁自你頭上竄出，你的極火功\更加熟練了!! \n");
	
}
string exert_function_file(string act)
{

  return PERFORM_D("fireforce/") + act;
}

string perform_action_file( string func)
{
   return PERFORM_D("fireforce/") + func;
}


