inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG + "柳靈之印" + NOR,({"surname-yin"}));
	set("long","一塊注有柳之靈印，在靈印上面不時的閃爍著一點奇怪的靈光，任\n"
		  +"你如何的細看和研究，卻也不知它有何作用，也許\和傳說中的天靈\n"
		  +"地界有關。\n");
	set("unit","塊");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set("item_type","force");
	set("item_power",3);
	set_weight(1000);
        setup();
}
