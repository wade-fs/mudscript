inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"自由之貝殼"NOR,({"free-shells"}));
	set("long","一個奇怪的貝殼，似乎並不怎麼值錢，上面傳遞著自由的意念，任\n"
		  +"你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的天靈\n"
		  +"地界有關。\n");
	set("unit","個");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
