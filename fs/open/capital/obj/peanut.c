// dumpling.c

inherit ITEM;
					
void create()
{
	set_name("椒鹽花生", ({ "peanut" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一袋灑滿特製鹽巴，看起來很好吃的花生。\n");
		set("unit", "個");
		set("value", 30);
		set("食物", ([
                        "剩" : 10,       // 可以吃幾口
                        "供應": 17,     // 每一口填飽肚子的量
                ]) );
	}
        setup();
}
