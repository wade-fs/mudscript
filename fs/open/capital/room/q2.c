// Room: /open/capital/room/g2
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "石室");
	set( "build", 28 );
  set ("long", @LONG
這裡是一間封閉的地下石室, 但不知從哪裡有陣陣的空氣流通, 因
此也不覺得窒礙, 四周擺著一些石桌(table)石椅(chair), 顯然是以大
力劈成。

LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "table" : "一張普通的石桌, 沒有啥出奇的地方, 不過看來很厚重, 推都推不動。
",
  "chair" : "劈成歪歪斜斜的椅子, 不過就是還蠻穩固的。
",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/duan2" : 1,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"q1",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "table" : "雖然這石桌重的無法移動, 但在你契而不捨的努力下, 終於發現這石桌似乎可以轉動(turn)。
",
]));

  setup();
}
void init()
{
	add_action("do_turn","turn");
	add_action("do_climb","climb");
}
int do_turn(string str)
{
	if( str != "table" )
	  return notify_fail("轉什麼?\n");
        if( present("great thief",this_object()) || present("chao",this_object()) )
	  return notify_fail("大盜擋著你說道﹕動手動腳的做什麼?\n");
	set_temp("open_hole",1);
	tell_room(this_object(),"你用盡全身的力量轉動石桌, 隨著嘎拉嘎拉的聲音, 石室頂上露出一個大洞。\n看來似乎可以從這個洞爬(climb)出去說。\n");
	set ("long", @LONG
這裡是一間封閉的地下石室, 但不知從哪裡有陣陣的空氣流通, 因
此也不覺得窒礙, 四周擺著一些石桌(table)石椅(chair), 顯然是以大
力劈成。
    石室上頭露出一個大洞。	  

LONG);
	return 1;
}
int do_climb(string str)
{
	object me=this_player();
	if( !this_object()->query_temp("open_hole") )
	  return notify_fail("這裡沒有洞可以爬出去。\n");
    message_vision("$N施展輕功\縱身一跳, 跳出了這個石室。\n",me);
	me->move(MAIN_ROOM"s18");
	return 1;
}
	
