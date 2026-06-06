inherit ROOM;

void create ()
{
  set ("short", "外海");
  set ("long", @LONG



	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	雖然定水珠可以幫助你在水中移動，但是並不代表沒有人會攻擊你！
	而且這裡似乎水溫有越來越低的趨勢，看來定水珠並沒有保溫的效果。
	目前海岸離你並不是很遠，但是海中的生物已經很多了。。。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"landrm3",
  "west" : __DIR__"landrm1.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/killer/sea/npc/auklet.c" : 2,
  "/open/killer/sea/npc/auk.c" : 1,
]));
  set("light_up", 1);

  setup();
}

int valid_leave(object me, string dir)
{
  int max;
 object ob2;

 if ( !present("static_water",this_player()) )  //檢查玩家是否有定水珠
 {//如果沒有定水珠，代表無法在水中移動

	   me->add("kee",-20);
	   return notify_fail("你居然沒了定水珠，完蛋了.........你只能在海中漂流......\n");
}  
 //如果有定水珠就代表可以通過
 return 1;
}
