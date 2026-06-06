inherit ROOM;

void create()
{  
   
   set("short","外海");
set("long",@LONG
你憑藉著定水珠的神奇力量，自由自在的在海中行走
然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
海中的生物在你身旁自由的來去，他們似乎沒有敵意。
想到在武林中，爾虞我詐，你爭我奪，不禁羨慕起這些生物來。
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"fonrm3.c",  	
       "west" : __DIR__"fonrm5.c",  	
]));
set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/puffer_fish.c":3,
      "/open/killer/sea/npc/porgy_fish.c":1,
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
