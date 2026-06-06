inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"炎之紋章"NOR,({"fire-emblem"}));
	set("long","一枚看來帶點火的光亮的奇怪紋章，略帶點火熱的溫度，任你如何的\n"
		  +"細看和研究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
