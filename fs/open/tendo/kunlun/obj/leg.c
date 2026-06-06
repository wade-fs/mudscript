// chicken_leg.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("烤雞腿", ({ "fried chicken leg", "chicken", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枝烤得香噴噴雞腿﹐你還猶豫什麼﹖準備胃液吧。\n");
		set("unit", "根");
		set("value", 30);
		set("食物", ([
			"剩" : 4,	// 可以吃幾口
			"供應": 40,	// 每一口填飽肚子的量
		]) );
		set("wield_msg", "$N抓起一根$n﹐握在手中當武器。\n");
		set("material", "bone");
	}
        init_hammer(0);
	setup();
}

int finish_eat()
{
	set_name("啃得精光的雞腿骨頭", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的雞腿骨頭。\n");
	return 1;
}
