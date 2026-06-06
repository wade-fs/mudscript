inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC + "靛色光晶" + NOR,({"hiblue-crystal"}));
	set("long","一塊略呈靛色的光晶，在光晶上面不時的散發著奇怪的靈光，但任\n"
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
