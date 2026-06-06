// dumpling.c

inherit ITEM;
								
void create()
{
	set_name("糖葫蘆", ({ "sugarcoated haws on a stick" ,"stick"}) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "京城中超級好吃的糖葫蘆。\n");
		set("unit", "支");
		set("value", 10);
		set("食物", ([
                        "剩" : 2,       // 可以吃幾口
                        "供應": 30,     // 每一口填飽肚子的量
                ]) );
	}
        setup();
}
