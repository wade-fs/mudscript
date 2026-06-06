inherit ROOM;

void create()
{  
   
   set("short","近海");
   set ("long", @LONG


	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	海上風平浪靜，天上風和日麗，海中暗潮洶湧。
	海中生物自由來去，令你不禁想到，這些生物到底來自何方，到何處？
	
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "northeast" : __DIR__"fonrm8.c",  	
       "west" : __DIR__"fonrm6.c",  	
]));
set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/sail_fish.c":1,
      "/open/killer/sea/npc/hilabut_fish.c":1,
      "/open/killer/sea/npc/brra_fish.c":1,
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
 return 1;
}
