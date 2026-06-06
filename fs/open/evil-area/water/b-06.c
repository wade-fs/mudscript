inherit ROOM;

void create ()
{
	set("short","廚　房");
	set("long",@LONG
火燙的滾由正在你身旁的爐灶上加熱著，你小心翼翼的躲避著那
不時噴灑出來的熱油，只見得老婦人不斷的翻鍋，切蒜，擣肉，忙的
不可開交，你突然覺得自己在這裡彷彿礙人手腳...

地上擺滿了蜜罐。
LONG);
	set("no_fight", 1);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-05",
"south":__DIR__"b-08",
]));
	setup();
}

void init()
{
	if( this_player()->query_temp("evil/water/ask-mission-3") )
		add_action("do_search","search");
}

int do_search()
{
object ob;

	if( !this_player()->query_temp("evil/water/ask-mission-3") )
		return 0;

	ob = new(__DIR__"obj/nectar");
	message_vision("$N在地上搜尋著，結果發現了一些$n。\n",this_player(),ob);
	ob->move(this_player());
	this_player()->delete_temp("evil/water/ask-mission-3");
	return 1;
}
