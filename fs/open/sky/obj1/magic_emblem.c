inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM + "幻之紋章" + NOR,({"magic-emblem"}));
	set("long","一枚你幾乎快要不能掌握的奇怪紋章，若虛若幻，名為幻之紋章，\n"
		  +"任你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的傳\n"
		  +"說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
