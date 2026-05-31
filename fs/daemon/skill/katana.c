//katana:太刀....浪人用的武器          made by eva

inherit SKILL;

mapping *actions = ({
    ([ "action":        "$N漫無章法的拿$w向$n$l斬去",
		"damage_type":	"割傷",
	]),
    ([  "action":       "$N胡亂揮動$w往$n$l砍去",
		"damage_type":	"斲傷",
	]),
    ([  "action":       "$N凝神用力往$n$l刺去",
		"damage_type":	"刺傷",
	]),
	([	"action":		"$N揮動手中$w﹐削向$n$l",
		"damage_type":	"刺傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}

string perform_action_file( string func)
{
   return PERFORM_D("katana/") + func;
}

