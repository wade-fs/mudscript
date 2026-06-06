inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","蛇寨 地下室");
	set("long",@LONG
這裡擺放著許多的火把～在火把包圍的中央，有一塊微微凸起的
石塊，在石塊的北邊不遠處有一道石門，石門上刻著蛇的雕像。
LONG);
	set("item_desc",([
"火把":"熊熊的烈火不斷的燃燒著火把。\n",
"石塊":"石塊上似乎能放置某種物品...\n",
"門":"門上雕刻著蛇的畫像，並且緊閉著。\n",
"石門":"門上雕刻著蛇的畫像，並且緊閉著。\n",
"door":"門上雕刻著蛇的畫像，並且緊閉著。\n",
]));
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"r-42",
]));
	setup();
}

void init()
{
add_action("do_put","put");
add_action("do_enter","enter");
}

int do_put(string arg)
{
object me;

	me = this_player();

	if( !arg )
		return 0;
	if( arg != "snake statue" && arg != "statue" )
		return 0;

	if( !present("snake-key-2",me) )
		return notify_fail("你嘗試著將蛇雕像擺\上去，不過大小似乎不一樣。\n");

	message_vision("$N順利的將雕像擺\上去～\n",me);
	call_out("door",3,me);
	destruct(present("snake-key-2",me));
return 1;
}

int door(object me)
{
	message_vision("門緩緩的開啟了。\n",me);
	set("exits/north",__DIR__"r-44");
return 1;
}

int valid_leave(object me,string dir)
{
	if( dir == "north" )
	{
		message_vision(HIY + "$N一踏過門檻，門就隨即關上。\n" + NOR,me);
		delete("exits/north");
	}
return 1;
}
