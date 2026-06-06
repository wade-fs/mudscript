inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

你一走進這裡直覺就告訴你，這裡是地道的出口了，你把四周的石壁仔仔
細細的看過一遍，終於在左下角的石壁上發現有一塊石頭（stone） 似乎
可以推（push）進去。

LONG);

  set("light_up",0);
  set("exits", ([ /* sizeof() == 2 */
  "north" :__DIR__"c1-1.c",
  "west" :__DIR__"c2-8.c",
]));

  setup();
}
void init()
{
        add_action("do_push","push");
        add_action("do_climb","climb");
}
int do_climb(string str)
{
        if(!str || str != "stair")
        return notify_fail("爬？你想爬去那裡？\n");
        message_vision("$N飛步爬上樓梯。\n",this_player() );
        this_player()->move("/open/gblade/room/g1-2.c");
        message_vision("$N從桌子底下鑽出來，桌子又自動歸回原位了，真是巧妙的設計阿。\n",this_player());
return 1;
}
int do_push(string str)
{
        if(!str || str != "stone")
	return notify_fail("你要推哪裡啊 !\n");
	if(this_player()->query_str()+this_player()->query("force")/10 <50 )
	return notify_fail("你的力氣好像太小了一點。\n");
     if(query("stone_pushed") )
        return notify_fail("石頭已經被人動過了啦 !\n");
        message_vision("$N用盡全身的每一分力氣用力的推....石頭突然往內陷了進去。\n",this_player() );
        message_vision("突然身旁的石壁往旁邊移了開來，露出了一個階梯。\n",this_player() );
        set("stone_pushed",1);
        set("long", @LONG

你終於發現了地道的出口，想到可以離開這一個可怕的地道，你的心中感
到無限的喜悅。一條樓梯(stair)往上通往出口。

LONG);
set("item_desc", ([
"stair": "
階梯似乎可以通到外面。
",
]));
return 1;
}

