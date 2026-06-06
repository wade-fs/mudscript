
inherit ITEM;

void create()
{
	set_name("人肉叉燒包", ({ "dumpling" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個頗大的包子, 聽說肉餡是用人肉做的.\n");
		set("unit", "個");
		set("value", 30);
		set("食物", ([
                        "剩" : 5,       // 可以吃幾口
                        "供應": 70,     // 每一口填飽肚子的量
                ]) );
	}
	setup();
}
