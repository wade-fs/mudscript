inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG + "雲之紋章" + NOR,({"cloud-emblem"}));
	set("long","一枚如雲似霧讓你快看不清的的奇怪紋章，若隱若現，名為雲之紋\n"
		  +"章，任你如何的細看和研究，卻也不知它有何作用，也許\和傳說中\n"
		  +"的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
