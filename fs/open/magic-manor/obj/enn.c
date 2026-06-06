inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("不知名的東西",({"unknow item","item"}));
	set("long","一塊看起來完全不起眼的東西，握在手中卻可以感覺到它的厚實和\n"
		  +"笨重，為醉問天所有的東西，卻被神秘飛賊所偷走。\n");
	set("unit","塊");
	set("value",100000);
	set("magic-manor",1);
	set("no_sac",1);
	set_weight(1000);
        setup();
}
