inherit ROOM;

void create ()
{
	set("short","廚　房");
	set("long",@LONG
廚房是個四四方方的石磚屋，你可以看到各式的炊坎工具與一些
調味品，眼前有一個長的與人頗為類似，不過卻有著一個長長且尖銳
的耳朵，感覺上彷彿是一個精靈，不過似乎有一把年紀的感覺。

地上擺滿了棉草。
LONG);
	set("no_fight", 1);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"b-04",
"east":__DIR__"b-06",
"south":__DIR__"b-07",
]));
	setup();
}

void init()
{
	if( this_player()->query_temp("evil/water/ask-mission-2") )
		add_action("do_search","search");
}

int do_search()
{
object ob;

	if( !this_player()->query_temp("evil/water/ask-mission-2") )
		return 0;

	ob = new(__DIR__"obj/grass");
	message_vision("$N在地上搜尋著，結果發現了一些$n。\n",this_player(),ob);
	ob->move(this_player());
	this_player()->delete_temp("evil/water/ask-mission-2");
	return 1;
}
