// chicken_leg.c

#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("特製川辣雞腿", ({ "chicken leg", "chicken", "leg" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一枝通體鮮紅的雞腿，沾過特製的辣醬。\n");
		set("unit", "根");
		set("value", 300);
		set("食物", ([
                        "剩" : 5,       // 可以吃幾口
                        "供應": 60,     // 每一口填飽肚子的量
                ]) );
		set("wield_msg", "$N抓起一根$n﹐握在手中當武器。\n");
		set("material", "bone");
	}
	init_hammer(2);
	setup();
}

int finish_eat()
{
	set_name("啃得精光的雞腿骨頭", ({ "bone" }) );
	set_weight(150);
	set("long", "一根啃得精光的雞腿骨頭。\n");
	return 1;
}
