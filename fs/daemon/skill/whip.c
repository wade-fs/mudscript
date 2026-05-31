// whip.c

inherit SKILL;

mapping *actions = ({
    ([  "action":		"$N揮動$w﹐往$n$l砸了過去",
        "damage_type":  "瘀傷",
	]),
     ([  "action":		"$N揮舞手中的$w﹐「呼」的一聲往$n$l當頭砸下",
        "damage_type":  "瘀傷",
	]),
    ([  "action":       "$N掄起手中$w﹐照準$w$l狠狠地揮將過去",
        "damage_type":  "瘀傷",
	]),
    ([  "action":       "$N「嘿」地一聲﹐抄起手中$w對準$n$l奮力一擊",
        "damage_type":  "瘀傷",
	]),
    ([  "action":      "$N將$w使發了性子﹐憑著一股蠻勁往$n$l掃了過去",
        "damage_type":  "瘀傷",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}


