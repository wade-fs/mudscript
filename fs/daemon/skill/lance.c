// blade.c

inherit SKILL;

mapping *actions = ({
    ([  "action":       "$N往前一捅﹐$w一槍捅了過去",
        "damage_type":  "捅傷",
	]),
  ([  "action":       "$N尋著空隙﹐一個箭步上前手中$w便往$n$l刺去",
		"damage_type":	"刺傷",
	]),
    ([  "action":       "$N手中$w一插﹐一槍刺向$n$l",
        "damage_type":  "捅傷",
	]),
    ([  "action":       "$N對準$n$l一槍揮了過去",
        "damage_type":  "割傷",
	]),
    ([  "action":       "$N反轉手中$w﹐「唰」地一聲往$n$l搥去",
        "damage_type":  "瘀傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}


