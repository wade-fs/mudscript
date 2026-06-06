inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"心之化羽"NOR,({"heart-feather"}));
	set("long","一根帶著微弱心跳的羽毛，隱約的透出幾點光茫，名為心之化羽，任\n"
		  +"你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的天靈地\n"
		  +"界有關。\n");
	set("unit","根");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
