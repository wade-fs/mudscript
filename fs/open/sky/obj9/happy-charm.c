inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIY"快樂之符"NOR,({"happy-charm"}));
	set("long","一塊名為快樂之符，上面刻著奇形怪狀的文字包圍著快樂兩字，任\n"
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
