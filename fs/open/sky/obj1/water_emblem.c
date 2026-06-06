inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIB + "水之紋章" + NOR,({"water-emblem"}));
	set("long","一枚看來泛著點水氣和奇異藍色光茫的奇怪紋章，任你如何的細看和\n"
		  +"研究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
