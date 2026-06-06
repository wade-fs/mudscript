inherit ROOM;

void create()
{
	set("short","蛇寨");
	set("long",@LONG
這裡有一扇門，門扇兩旁分別雕飾著一條蛇，蛇身上有著一些你
無法理解的文字與圖形。
LONG);
	set("item_desc",([
"door":"門中央有著一個蛇型的標誌。\n",
"門":"門中央有著一個蛇型的標誌。\n",
"蛇型":"它是一個蛇型的凹槽，似乎可以放置什麼東西...\n",
"標誌":"它是一個蛇型的凹槽，似乎可以放置什麼東西...\n",
]));
	set("objects",([
__DIR__"npc/snake_soldier":2,
]));
	set("exits",([
"west":__DIR__"r-11",
"east":__DIR__"r-09",
"south":__DIR__"r-03",
]));
	setup();
}

void init()
{
add_action("do_put","put");
}

int do_put(string arg)
{
object me,ob;

	me = this_player();

	if( !arg )
		return 0;
	if( arg != "snake statue" && arg !="statue" )
		return 0;
	if( !present("snake-key-1",me) )
		return notify_fail("你怎麼擺\都無法將東西擺\入凹槽內，似乎不合。\n");

	message_vision("$N將蛇型雕像擺\入了凹槽內～\n",me);
	call_out("door",3,me);
	destruct(present("snake-key-1",me));
return 1;
}

int door(object me)
{
object ob = this_object();

	message_vision("大門緩緩的打開～\n",me);
	set("exits/north",__DIR__"r-05");
return 1;
}

int valid_leave(object me,string dir)
{
	if( present("snake-soldier",environment(me)) )
	{
		message_vision("守衛大喝：兄弟們～別讓"+me->name(1)+"跑了～\n",me);
		return notify_fail("你的退路已經被擋住了。\n");
	}
	if( dir == "north" )
	{
		message_vision("$N一走過門檻，大門又隨即關上。\n",me);
		delete("exits/north");
	}
return 1;
}
