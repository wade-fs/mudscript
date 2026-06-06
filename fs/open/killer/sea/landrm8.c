inherit ROOM;

void create ()
{
  set ("short", "神仙島港外");
  set ("long", @LONG



	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	神仙島港就在你的東邊，水溫也接近冰點了。
	面對茫茫的大海，你心中不禁有點擔心。
	
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"landrm7.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/sea/npc/cok_fish.c" : 2,
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
 me->add("kee",-10);
 return 1;
}
