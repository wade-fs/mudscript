// Room: /u/r/ranko/room/pa1.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
這是一條彎彎曲曲的小路，路上石子不少，踩在腳底怪不舒服
的，不時還得注意地上以免被絆倒了，兩旁雜草叢生，似乎欠缺人
來打理。路旁有條小徑通往一間小木屋，你不禁感到奇怪究竟是誰
住在此處呢。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"v3.c",
]));
  set("outdoors", "/open/poison");

  setup();
}

void init()
{
	add_action("do_enter","enter");
}
int do_enter(string str)
{
	object me=this_player();
		if(!str || str!="hut")
	return notify_fail("你想進入那裡呀?\n");

	message_vision("$N穿過小徑，走到小木屋門前。\n",me);
	tell_room(me,"你推開了木門走進屋內，赫然發現內裡住著一位將軍模樣的人。\n");
	me->move(__DIR__"v10.c");
	return 1;
}
		                   

