// meal.c

inherit ITEM;

void create()
{
	set_name("特製大餐\", ({ "special meal", "meal" }));
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一盤香味四溢的惡人谷特製大餐\，不知道是什麼做的。\n");
		set("unit", "盤");
		set("value", 250);
		set("食物", ([
                        "剩" : 5,       // 可以吃幾口
                        "供應": 80,     // 每一口填飽肚子的量
                ]) );
	}
	setup();
}

int finish_eat()
{
	object who = this_player();
	tell_object(who,"咦？怎麼吃到一根脆脆的？這...這不是人的手指嗎？天哪！難不成...\n");
	tell_object(who,"想到這裡，你真想把剛剛吃的東西全部吐出來。\n");
	destruct(this_object());
	return 1;
}
