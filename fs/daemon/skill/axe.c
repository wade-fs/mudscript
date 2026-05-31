// axe.c

inherit SKILL;

mapping *actions = ({
    ([  "action":       "$N往前一劈﹐$w劈了過去",
        "damage_type":  "劈傷",
	]),
([  "action":       "$N尋著空隙﹐一個箭步上前手中$w便往$n$l砍去",
        "damage_type":  "砍傷",
	]),
    ([  "action":       "$N手中$w一轉﹐劈向$n$l",
        "damage_type":  "劈傷",
	]),
    ([  "action":       "$N對準$n$l揮了過去",
        "damage_type":  "砍傷",
	]),
    ([  "action":       "$N反轉手中$w﹐「唰」地一聲往$n$l劈去",
        "damage_type":  "劈傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}


