inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"土之紋章"NOR,({"soil-emblem"}));
	set("long","握在手中可以感覺到大地的氣息不斷地從中飄來，一枚稱為土之紋章\n"
		  +"的奇怪東西，任你如何的細看和研究，卻也不知它有何作用，也許\和\n"
		  +"傳說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
