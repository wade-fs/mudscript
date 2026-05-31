// stabber.c

inherit SKILL;

mapping *actions = ({
	([  "action"     :	"$N將$w往前一送﹐直刺$n$l",
	    "damage_type":	"刺傷",
	]),
	([  "action"     :	"$N揮舞$w﹐對準$n$l刺去",
	    "damage_type":	"刺傷",
	]),
	([  "action"     :	"$N高舉手中$w﹐往$n$l揮了過去",
	    "damage_type":	"斲傷",
	]),
	([  "action"     :	"$N將$w一揮﹐往$n$l用力刺落",
	    "damage_type":	"刺傷",
	]),
	([  "action"     :	"$N尋著空隙﹐手中$w對準$n$l揮了過去",
	    "damage_type":	"割傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}

