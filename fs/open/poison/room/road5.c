// Room: /open/poison/room/road5
inherit ROOM;

void create ()
{
  set ("short", "瀑布");
  set ("long", @LONG
眼前有一道瀑布(waterfall) 由峰頂直洩而下，氣勢雷
廷萬千，經由陽光照射，在瀑旁形成一道七彩虹橋，瀑水衝
擊岩石，激起陣陣水花，附近水氣瀰漫，如夢如幻，如痴如
醉，婉如人間仙境般。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "waterfall" : "此道瀑布十分美麗壯觀，在你眼前形成一道寬廣的簾幕，瀑
旁岩石並沒有生長青苔，看起來似乎是常有人行走的結果，
不知瀑布後是否別有洞天。
",
]));

  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/poison/room/road4",
]));

  setup();
}
void init()
{
	add_action("do_enter","enter");
}

int do_enter(string str)
{
	object me;
	me = this_player();
	
	if(!str || str != "waterfall")
		return notify_fail("你想進入哪裡？\n");
	else {
		tell_object(me,"隨身一轉, 你輕巧地進入瀑布後的山洞。\n");
		me->move("/open/poison/room/room5");
	     }
	return 1;
}
