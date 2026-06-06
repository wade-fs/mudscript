inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"天樞星玉"NOR,({"shue-jade"}));
	set("long","七星玉中的天樞星玉，帶點星光的流動氣息閃爍迷人，但任如如何的\n"
		  +"細看和研究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","塊");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
