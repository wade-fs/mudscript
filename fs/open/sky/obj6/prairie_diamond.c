inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC"草原之青鑽"NOR,({"prairie-diamond"}));
	set("long","一顆奇怪的鑽石，似乎並不怎麼值錢，上面刻畫著草原的圖案，任\n"
		  +"你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的天靈\n"
		  +"地界有關。\n");
	set("unit","顆");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
