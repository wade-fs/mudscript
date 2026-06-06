inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM + "櫻桃娃娃" + NOR,({"cherry-doll"}));
	set("long","一個櫻桃形狀的娃娃，在娃娃上面不時的散發著奇怪的靈光，但任\n"
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
