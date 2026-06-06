// luwei.c

inherit ITEM;

void create()
{
	set_name("滷味", ({ "lu wei", "lu", "wei" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盤香噴噴，令人口水直流的滷味。\n");
		set("unit", "盤");
		set("value", 100);
		set("食物", ([
                        "剩" : 4,       // 可以吃幾口
                        "供應": 50,     // 每一口填飽肚子的量
                ]) );
	}
	setup();
}
