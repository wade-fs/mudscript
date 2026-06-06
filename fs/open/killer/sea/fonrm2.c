inherit ROOM;

void create()
{  
   
   set("short","近海");
   set ("long", @LONG


	你憑藉著定水珠的神奇力量，自由自在的在海中行走
	然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
	雖然定水珠可以幫助你在水中移動，但是並不代表沒有人會攻擊你！
	目前海岸離你並不是很遠，但是海中的生物已經很多了。。。
	看來他們自由自在的游著，想到自己在武林中沈浮便感到一陣落寞感。。。

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"fonrm1.c",  	
       "east" : __DIR__"fonrm3",  	
]));
set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/stone_fish.c":1,
      "/open/killer/sea/npc/angler_fish.c":1,
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
