inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(CYN + "風之紋章" + NOR,({"wind-emblem"}));
	set("long","握在手中可以感覺到有陣陣的風在指尖流動著，一枚稱為風之紋章的\n"
		  +"奇怪東西，任你如何的細看和研究，卻也不知它有何作用，也許\和傳\n"
		  +"說中的天靈地界有關。\n");
	set("unit","枚");
	set("value",100000);
	set("specialitem",1);
	set("no_sac",1);
	set("no_save",1);
	set_weight(1000);
        setup();
}
