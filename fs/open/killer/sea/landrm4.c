inherit ROOM;

void create()
{  
   
   set("short","外海");
   set ("long", @LONG


	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	海中的生物在你身旁自由的來去，他們似乎沒有敵意。
	奇怪，這些魚為何不怕冷呀？你都快冷的受不了說。。。
	
LONG);
  set("light_up", 1);
    set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"landrm3.c",  	
       "north" : __DIR__"landrm5", 
      "southeast" : __DIR__"fonrm5",  	
]));

set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/auklet.c":3,
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
me->add("kee",-2);
 return 1;
}
