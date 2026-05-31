// dagger.c

inherit SKILL;

mapping *actions = ({
	([	"action":		"$N提起手中$w猛然往$n$l刺去",
		"damage_type":	"刺傷",
	]),
	([	"action":		"$N揮動$w﹐往$n$l劃了過去",
		"damage_type":	"割傷",
	]),
	([	"action":		"$N緊握手中$w﹐對準$n$l刺了過去",
		"damage_type":	"刺傷",
	]),
	([	"action":		"$N揮動手中$w﹐削向$n$l",
		"damage_type":	"割傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof(actions))];
}


