inherit ROOM;
void create()
{
set("short", "秘密種植室");
set("long", @LONG
四周水氣瀰漫,又有奇異的光芒，帶著異常的寒冷，或許這裡種著寒帶植物。
這裡真是個隱密的所在。。。。。

LONG );
set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"outr5.c",
]));
	set("no_transmit",1);
setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();

  if (arg)
     return notify_fail("你找來找去也沒發現什麼特殊的地方。\n");
  message_vision("$N發現了富士山秘草，順手拔了一把。\n", me);
  new("/open/killer/obj/herb.c")->move(me);
  message_vision("但似乎有人發現你的存在，於是你立刻翻了出去\n", me);
  set_temp("tree_hold",0);
  me->move(__DIR__"outr5.c");
  return 1;
}
