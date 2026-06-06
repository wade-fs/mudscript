inherit ROOM;

void create()
{  
   
   set("short","海洋");
set("long",@LONG
你憑藉著定水珠的神奇力量，自由自在的在海中行走
然而為了避免迷路與避開危險地帶，所以你最好跟著航線走。
茫茫大海，令你感到造物者的神奇，或許以人類的力量早晚也能到天空吧？
然而，眼前的課題是--------我要上岸！！！
你因為你實在是冷得快受不了了。。。。。。。
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"landrm4.c",  	
       "west" : __DIR__"landrm6.c",  
]));
set("objects", ([ /* sizeof() == 1 */
      "/open/killer/sea/npc/big_fish.c":1,
      "/open/killer/sea/npc/auk.c":1,
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
me->add("kee",-5);
 return 1;
}
