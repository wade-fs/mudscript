// open/killer/ninja/find/9block.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short","九宮迷陣起點");
  set ("long", @LONG
  
    看來你來到了一個奇怪的地方，一旁有一個告示牌
    『此為九宮迷陣的起點，往北將正式進入迷宮
      如果在迷宮中發生任何錯誤，將會退回到起點』
    
LONG);
 
  set("exits", ([ /* sizeof() == 1   */
      "north" : __DIR__"9block2.c",   ]));
  set("no_transmit",2);
  setup();
}

void init()
{
    this_player()->delete_temp("wrongway");
}
