inherit ITEM;

void create()
{
	set_name("便當", ({ "bento" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一個香噴噴、熱騰騰的大便當。\n");
		set("unit", "個");
		set("value", 200);
		set("weight",3000);
		set("食物", ([
                        "剩" : 20,       // 可以吃幾口
                        "供應": 80,     // 每一口填飽肚子的量
                ]) );
	}
        setup();
}
