inherit ROOM;
#include "way.c"

void create()
{
	set("short","蛇寨 置物室");
	set("long",@LONG
這是一個半大不小的密閉空間，你可以看到北方有一個蛇型的座
椅，不過如果說是蛇寨寨主的王座，似乎又顯得有點小氣，週遭擺滿
了許多的黃金與珠寶，看來這裡是放置寶物的地方。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/snake_soldier":3,
]));
	set("exits",([
"east":__DIR__"r-17",
"west":__DIR__"r-21",
"north":__DIR__"r-19",
]));
	setup();
}

void init()
{
add_action("do_search","search");
add_action("do_turn","turn");
}

int do_search()
{
object me = this_player();

	tell_object(me,"你仔細的搜索著附近，發現了在你身後有一個蛇型的轉輪。\n");
	me->set_temp("snake/search",1);
return 1;
}

int do_turn()
{
object me;

	me = this_player();

	me->delete_temp("snake/search");
	tell_object(me,"你嘗試著轉動蛇型轉輪，結果觸動了機關～\n");
	message_vision("$N轉出了門外!!\n",me);
	me->move(__DIR__"r-04");
return 1;
}
	
