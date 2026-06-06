inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"冰之紋章"NOR,({"ice-emblem"}));
	set("long","一枚看來帶點冰冷溫度和奇異藍光的奇怪紋章，任你如何的細看和研\n"
		  +"究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
