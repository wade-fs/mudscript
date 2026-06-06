inherit ROOM;

void create()
{  
   
   set("short","外海");
   set ("long", @LONG


	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	水溫已經降到蠻低的，令你不禁叫苦連天。
	目前海岸離你已經很遠，海中的生物在你身旁自由的來去。
	

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"landrm2.c",  	
       "north" : __DIR__"landrm4",  	
]));

set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/brra_fish.c":2,
      "/open/killer/sea/npc/gull.c":2,
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
me->add("kee",-2);
 return 1;
}
