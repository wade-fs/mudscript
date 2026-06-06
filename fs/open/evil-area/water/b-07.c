inherit ROOM;

void create ()
{
	set("short","廚　房");
	set("long",@LONG
這裡置放著許多的雜物，不過卻沒有凌亂的感覺，每一樣物品似
乎都有定時被清洗著，一點灰塵都沒有，就連擺放於地上的木材都十
分的乾淨...真是太不可思議了，誰會勤勞到連木材都在整理ㄋ...看
來答案似乎就是身在這裡的婦人...

地上擺滿了木材。
LONG);
	set("no_fight", 1);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-05",
"east":__DIR__"b-08",
]));
	setup();
}

void init()
{
	if( this_player()->query_temp("evil/water/ask-mission-1") )
		add_action("do_search","search");
}

int do_search()
{
object ob;

	if( !this_player()->query_temp("evil/water/ask-mission-1") )
		return 0;

	ob = new(__DIR__"obj/torch");
	message_vision("$N在地上搜尋著，結果發現了一些$n。\n",this_player(),ob);
	ob->move(this_player());
	this_player()->delete_temp("evil/water/ask-mission-1");
	return 1;
}
 
 
