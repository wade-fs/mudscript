// blade.c

inherit SKILL;

mapping *actions = ({
    ([  "action":		"$N手腕一翻﹐$w往$n$l砍了過去",
        "damage_type":  "斲傷",
	]),
    ([  "action":		"$N尋著空隙﹐一個箭步上前手中$w便往$n$l砍落",
		"damage_type":	"刺傷",
	]),
    ([  "action":       "$N手中$w一揚﹐一刀斬向$n$l",
		"damage_type":	"斲傷",
	]),
    ([  "action":       "$N對準$n$l一刀揮了過去",
        "damage_type":  "割傷",
	]),
    ([  "action":       "$N橫過手中$w﹐「唰」地一聲往$n$l削去",
        "damage_type":  "割傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}


string perform_action_file( string func)
{
return PERFORM_D("blade/") + func;
}
