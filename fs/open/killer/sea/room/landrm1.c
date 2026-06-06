inherit ROOM;

void create ()
{
  set ("short", "外海");
set("long",@LONG
你身在東津港外 ，你憑藉著定水珠的神奇力量，自由自在的在海中行走
然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
雖然定水珠可以幫助你在水中移動，但是並不代表沒有人會攻擊你！
所以你最好自己小心一點，因為你的身形在水中看起來，就跟食物一樣。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"landrm2",
  "west" : "/open/killer/outsea/sea01.c",
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
 return 1;
}
