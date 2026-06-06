inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("闇之紋章",({"dark-emblem"}));
	set("long","一枚看來一點光彩也沒有的奇怪紋章，名為暗之紋章，任你如何的細\n"
		  +"看和研究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
