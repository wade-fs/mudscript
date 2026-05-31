// security.c

inherit SKILL;

int valid_enable(string usage) { return usage=="plan"; }

int valid_learn(object me)
{
            if( me->query("max_force") < 4000 ) {
            tell_object(me, "你的內力修為不夠，最少要有四千點。\n");
            return 0;
        }
            if( me->query("force") < 600 ) {
            tell_object(me, "你目前的內力不到六百點，無法練此計謀。\n");
            return 0;
        }
            if( me->query_skill("god-plan", 1) < 100 ) {
            tell_object(me,"你的諸葛神算不夠純熟，最少需要一百級。\n");        
            return 0;
        }
            if( !me->query("mark/sixgod-plan",1) ) {
            tell_object(me, "你還沒拿到六韜奇略這本書吧?\n");
            return 0;
        }
            if( (me->query("potential") - me->query("learned_points")) < 5 ) {
            tell_object(me, "你的潛能不到五點，無法練此計謀。\n");
            return 0;
        }
      tell_object(me, "學此計謀需扣潛能五點。\n");
            me->add("potential", -5);
            return 1;
}

int practice_skill(object me)
{
    return notify_fail("六韜奇略只能用學的。\n");
}


string perform_action_file( string action )
{
if( this_player()->query("race") !="人類" )


   {
      tell_object( this_player(), "你不是儒門,怎麼用六韜奇略???\n");
      action= "null_plan";
   }
      return CLASS_D("scholar") + "/sixgod-plan/" + action;
}

