// sword.c

inherit SKILL;

mapping *actions = ({
	([	"action":		"$N用手中的$w往$n$l斬去",
		"damage_type":	"割傷",
	]),
	([	"action":		"$N揮動$w﹐往$n$l砍去",
		"damage_type":	"斲傷",
	]),
	([	"action":		"$N將手中$w對準$n$l一劍刺去",
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
   return PERFORM_D("sword/") + func;
}

