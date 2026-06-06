// Room: /u/r/ranko/garden6.c
inherit ROOM;

void create ()
{
  set ("short", "水井");
  set ("long", @LONG
此處是冥蠱教眾用來取水以供給其所種的毒花,毒草使用。正中
央立著一以巨形青石砌成的水井(Well),其深不見底,不知底下通往
何方。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "well" : " 你走近井邊,好奇的往下望去,只見底下一遍漆黑.一股清風由下往上徐徐吹撫你的
 面頰,底下似乎別有洞天.旁邊有一條打水時所用的繩子(rope),或者你可以順著繩子
 攀爬下去一探究竟。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"garden2-2.c",
]));
  set("light_up", 1);

  setup();
}
 void init()
{
	add_action("do_climb","climb");
}
int do_climb(string str)
{
	object me;
	me = this_player();
	if(!str || str != "rope")
		return notify_fail("你想做甚麼？\n");
                                                                                 
                
	message_vision("$N抓緊繩子,沿著井緣,緩緩地盪了下去.\n",me);
	tell_room(me,"到達井底,你赫然發現下面是一個極具規模的山洞.\n");
	me->move(__DIR__"cave3.c");
                  return 1;
           
                  
}
