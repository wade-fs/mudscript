inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"光之明羽"NOR,({"light-feather"}));
	set("long","一根帶著些微光彩的羽毛，隱約透出各種顏色光彩，名為光之明羽，\n"
		  +"任你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的天靈\n"
		  +"地界有關。\n");
	set("unit","根");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
