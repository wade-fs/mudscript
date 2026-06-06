inherit ITEM;

void create()
{
	set_name("炒豌豆",({"bean"}) );
	set_weight(100);
	if (clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一盤剛炒好的豌豆，用來當小菜是最合適不過了。\n");
		set("unit","盤");
		set("value",30);
		set("食物", ([
                        "剩" : 10,       // 可以吃幾口
                        "供應": 18,     // 每一口填飽肚子的量
                ]) );
		}
	setup();
}
