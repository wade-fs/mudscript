// dumpling.c

inherit ITEM;
								
void create()
{
	set_name("鹵蛋", ({ "egg" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一粒又大又香的鹵蛋，真想一口把它吞掉。\n");
		set("unit", "顆");
		set("value", 10);
		set("食物", ([
                        "剩" : 2,       // 可以吃幾口
                        "供應": 30,     // 每一口填飽肚子的量
                ]) );
	}
        setup();
}
