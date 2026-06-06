// dumpling.c

inherit ITEM;

void create()
{
	set_name("饅頭", ({ "bread" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long", "一個香噴噴、熱騰騰的大饅頭。\n");
		set("unit", "個");
		set("value", 15);
		set("食物", ([
                        "剩" : 3,       // 可以吃幾口
                        "供應": 60,     // 每一口填飽肚子的量
                ]) );
	}
	setup();
}
