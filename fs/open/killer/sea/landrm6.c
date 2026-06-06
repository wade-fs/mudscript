inherit ROOM;

void create()
{  
   
   set("short","海洋");
   set ("long", @LONG


	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	海上風平浪靜，天上風和日麗，海中暗潮洶湧。
	然而因為定水珠的神奇力量，讓你絲毫感覺不到海的威脅。
	但是的冷度時在讓你快哭出來了，這實在是好冷呀！！
	
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"landrm7.c",  	
       "east" : __DIR__"landrm5.c",  	
]));
set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/sail_fish.c":1,
      "/open/killer/sea/npc/gull.c":1,
      "/open/killer/sea/npc/auklet.c":1,
]));

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
me->add("kee",-5);
 return 1;
}
