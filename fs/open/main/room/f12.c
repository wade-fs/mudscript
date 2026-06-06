// Room: /open/main/room/F12.c

inherit ROOM;

void create ()
{
  set ("short", "密林");
	set( "build", 24 );
  set ("long", @LONG
這裡是一片濃密的森林，高大的樹木，交織的枝葉，竟將
天日給整個遮蔽住了。四周隱隱傳來野獸的低吼聲，更增添了
幾許恐怖的氣氛。當你正準備轉身離開時，腳底下似乎踩到了
什麼東西...

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/main/room/r26",
  "west" : "/open/main/room/m12",
  "north" : "/open/main/room/m7",
  "east" : "/open/main/room/r19",
]));

  setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search()
{
	object who;
	who = this_player();

	tell_object(who,"\n你趴在地上到處摸來摸去，突然發覺腳下一空，啊...
...............................................
...............................................
...............................................\n\n");
	tell_object(who,"碰！的一聲，你總算又回到了熟悉的地面，屁股差點開花。\n\n");
	who->move("/open/badman/room/t1");
	tell_room(this_object(),"你只聽到"+who->query("name")+"發出一聲殺豬似的慘叫，轉頭回去看時他卻已經不見了。\n");
	return 1;
}
