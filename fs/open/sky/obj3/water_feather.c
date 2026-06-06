inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC + "水之流羽" + NOR,({"water-feather"}));
	set("long","一根泛著些微水氣的羽毛，滋潤的氣息，帶給你無限的舒適，名為\n"
		  +"水之流羽，任你如何的細看和研究，卻也不知它有何作用，也許\和\n"
		  +"傳說中的天靈地界有關。\n");
	set("unit","根");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
