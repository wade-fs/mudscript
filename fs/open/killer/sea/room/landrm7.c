// 2001.12.11 新增前往東瀛島的路線
inherit ROOM;

void create()
{  
   
   set("short","神仙島港外海");
set("long",@LONG
你憑藉著定水珠的神奇力量，自由自在的在海中行走
然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
海岸線在遠遠的地方，海中的生物也逐漸的變少了。
然而水中的溫度，也更低了。。。。。	
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"landrm6.c",
   //     "west" : "/open/killer/ninja/room/sea01.c",  	
       "south" : __DIR__"landrm8.c",  	
]));
set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/bunk_fish.c":1,
      "/open/killer/sea/npc/hake_fish.c":1,
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
me->add("kee",-10);
 return 1;
}
