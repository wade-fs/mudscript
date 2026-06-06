// Room: /u/r/ranko/garden7.c
inherit ROOM;

void create ()
{
  set ("short", "山壁");
  set ("long", @LONG
走到此處,你赫然發現一如小山般的峭壁聳立西方.往上看去,壁
上寸草不生,光禿禿的一片像似被甚麼削過似的光滑.看其高度,沒有
絕世輕功恐難攀登.山上不時隱現陣陣霞光,似有稀世珍寶藏於其中,
山腳下仍是種著各式各樣的毒花,毒草.但其中有一處草叢(bushes)似
乎特別茂密,不禁引起你的好奇心想一探究竟。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "bushes" : "你往草叢望去,發現這裡似乎隱藏了甚麼東西。你不妨四處搜尋一番,看看有何發現。
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden2-2.c",
  "east" : __DIR__"garden4-1.c",
]));
  set("light_up", 1);
  set("be_get",0);

  setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string str)
{
	object me=this_player();
	if(!str || str!="bushes")
	{return 0;}
	if(me->query_temp("get_fruit") && query("be_get"))
	{ message_vision("$N找了半天,但一無所獲。\n",me);
	  return 1;
	}
	message_vision("$N伸手撥開草叢，在一陣搜尋中幸運的發現一顆果子。\n",me);
	new("/open/poison/obj/fruit.c")->move(me);
	me->set_temp("get_fruit",1);
	set("be_get",1);
	return 1;
}
void reset()
{
set("be_get",0);
:: reset();
}
