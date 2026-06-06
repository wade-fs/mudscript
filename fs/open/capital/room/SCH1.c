// Room: /open/capital/room/SCH1
inherit ROOM;

void create ()
{
  set ("short", "書生公會書房");
  set ("long", @LONG
這間書房是楊書文的藏書所在, 楊書文一生的心血都放在這裡, 因
此這裡可不是一般人可以進來的, 若非楊書文的允許, 想看一看都不行
。入口處掛著一幅捲軸(paper)。

LONG);
  set("item_desc",([
  "paper"	:"請鍵入 <verify> 以得到自己的秘笈。\n",
  ]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"SCH",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}

void init()
{
	add_action("do_verify","verify");
}
int do_verify(string str)
{
	object me=this_player(),book;
	if( me->query("class") != "scholar" )
	  return notify_fail("本指令對非書生公會會員無效。");
    book=present("secret_book",me);
	me->set_temp("aa",book);
	while( book )
	{
	  destruct(book);
    book=present("secret_book",me);
	}
    book=new("/autoload/scholar/secret_book.c");
	book->move(me);
	message_vision("$N從書架上抽出自己的武功\秘笈。\n",me);
	return 1;
}
