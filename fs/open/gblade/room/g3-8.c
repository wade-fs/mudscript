inherit ROOM;

void create ()
{
  set ("short", "花圃");
  set ("long", @LONG

你順著花香走到了這裡，只見黃花滿地，白柳橫坡。小橋通若耶之溪，曲
徑接天台之路。石中清流滴滴，籬落飄香；樹頭紅葉翩翩，疏林如畫。再
往前走去，一樹花木皆無，只見許多異草，--或牽藤，或引蔓，或如翠帶
飄飄，或如金繩蟠屈，或實若丹砂，或花如金桂。--味香氣馥，非凡花可
比。面前一雙玉色蝴蝶，大如團扇，一上一下，迎風翩韆。一旁有婢女正
拿著扇子向草地下來撲。


LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gblade/npc/girl" : 1,
  "/open/gblade/npc/butterfly.c" : 2,
]));
  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"g3-2",
  "west" : __DIR__"g3-4",
  "south" : __DIR__"g3-6",
  "east" : __DIR__"g2-4",
]));

  setup();
}
void init()
{
	add_action("do_cover","cover");
}
int do_cover(string str)
{
	object ob;
	if(!present("net",this_player()))
	return 0;
	if(str!="butterfly")
	return notify_fail("你要抓什 ??\n");
	if(!ob=present("butterfly",environment(this_player())))
	return notify_fail("沒半隻啦 !\n");
	message_vision("$N用手中捕蟲網 , 往玉面蝴蝶罩去 \n",this_player());
	if(random(10)>6)
	{
	message_vision("結果唰的一聲 , $N登時動彈不得 \n",ob);
	new("/open/gblade/npc/butterfly")->move(this_player());
	destruct(ob);
	message_vision("$N從捕蟲網中將玉面蝴蝶拿出 \n",this_player());
	return 1;
	}
	message_vision("結果$N及時發現 , 躲了開去 \n",ob);
return 1;
}
