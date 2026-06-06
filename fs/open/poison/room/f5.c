// Room: /u/r/ranko/room/f1.c
inherit ROOM;

void create ()
{
  set ("short", "農田");
  set ("long", @LONG
一大片綠油油的田地橫亙在你面前，豐滿的稻穗幾乎將稻子壓
的貼近地面。不遠處正有許多農民正忙著收割，看來今年似乎是個
豐年。許多頑童正在收割過的田地上跑來跑去，玩的不亦樂乎，附
近不時飛過幾隻白鷺鷥，傳來幾聲嘶鳴聲。這裡有著一間以茅草搭
蓋成的茅屋(hut)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f4.c",
  "east" : __DIR__"f6.c",
]));
	set("item_desc", ([ /* sizeof() == 1 */
	"hut" : "一間小茅屋。\n",
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
	object me;
	me=this_player();
	if( !str || str!="hut")
		return notify_fail("你想進入那裡呀?\n");
	message_vision("$N鑽入了茅屋中。\n",me);
	me->move(__DIR__"hut.c");
	return 1;
}

