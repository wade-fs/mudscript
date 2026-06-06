// dumpling.c

inherit ITEM;

void create()
{
	set_name("香蒜大肉包", ({ "dumpling" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個令人垂涎愈滴的香蒜包子。\n");
		set("unit", "個");
		set("value", 200);
		set("food_remaining", 3);
		set("food_supply", 100);
		set("食物", ([
                        "剩" : 3,       // 可以吃幾口
                        "供應": 100,     // 每一口填飽肚子的量
                ]) );
	}
	setup();
}
