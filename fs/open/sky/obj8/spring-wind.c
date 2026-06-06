inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"春情風"NOR,({"spring-wind"}));
	set("long","帶著點風的質感，握在手中可以隱隱感覺到一陣暖風流過心中，任\n"
		  +"你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的天靈\n"
		  +"地界有關。\n");
	set("unit","塊");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
