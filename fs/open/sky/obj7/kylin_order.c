inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM"麒麟結令"NOR,({"kylin-order"}));
	set("long","一個奇怪的結令，看上去並不值錢，似乎代表著某種權力象徵，任\n"
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
