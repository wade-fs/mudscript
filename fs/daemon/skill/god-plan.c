// security.c

inherit SKILL;

int valid_enable(string usage) { return usage=="plan"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
   return notify_fail("諸葛神算只能用學的。\n");
}


string perform_action_file( string action )
{
if( this_player()->query("race") !="人類" )


   {
      tell_object( this_player(), "你不是儒門,怎麼用諸葛神算???\n");
      action= "null_plan";
   }
   return CLASS_D("scholar") + "/god-plan/" + action;
}

