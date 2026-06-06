// Room: /open/poison/room/room5
inherit ROOM;

void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
哇！沒想到瀑布後真的別有洞天，看來這裡好像是一個
廟堂，中間有座奇怪的石雕像(statue)，前面則有一個大香
爐(cencer)，整個石洞香煙裊裊的，不知是何人在此祭拜。
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "cencer" : "這是一個笨重的銅爐，看起來有轉動(turn)過的痕跡。
",
  "statue" : "令你十分驚訝，這竟然是座魔神雕像，莫非跟武林盛傳的冥
蠱神教有所關聯。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"road5",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/ranger.c" : 1,
]));

  setup();
}
void init()
{
	add_action("do_turn", "turn");
}

int do_turn(string str)
{
	object me;
	me = this_player();
	if(!str || str != "cencer")
		return notify_fail("你想轉動什麼？\n");
	else if(!query_temp("have_turn"))
		{
		  message_vision("$N費了九牛二虎之力，緩緩地轉動笨重的銅爐。\n",me);
		  tell_room(this_object(),"你發現西邊的石壁緩緩開啟, 出現一條密道。\n");
		  set("exits/west",__DIR__"path3");
		  set_temp("have_turn",1);
		  remove_call_out("do_closed");
		  call_out("do_closed",20);
		  return 1;
		}
	else {
	       remove_call_out("do_closed");
		delete_temp("have_turn");
		delete("exits/west");
		message_vision("$N運勁於雙掌，用力轉動機關，頓時一聲巨響，石門迅速合上。\n",me);
	     }
	return 1;
}

void do_closed()
{
	delete_temp("have_turn");
	delete("exits/west");
	tell_room(this_object(),"石璧緩緩地自動關了起來。\n");
}
