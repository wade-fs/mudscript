inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIB + "天尊石" + NOR,({"sky-stone"}));
	set("long","一顆看來帶點光亮的奇怪石頭，名為天尊石，任你如何的細看和\n"
		  +"研究，卻也不知它有何作用，也許\和傳說中的天靈地界有關。\n");
	set("unit","顆");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
