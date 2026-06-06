inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM"柔之絮羽"NOR,({"soft-feather"}));
	set("long","一根看來柔弱似是無力的羽毛，柔軟如絮名為柔之絮羽，任你如何的\n"
		  +"細看和研究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","根");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
