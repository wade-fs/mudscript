// Room: /open/capital/room/r49.c

#include "/open/capital/capital.h"
inherit ROOM;

void create()
{
	set("short","日升廣場");
	set("long",@LONG
一個中型的廣場。往南去是一條很寬的車馬大道，往北去是條一般
大小的胡同。廣場上小販聚集，熱鬧非凡。這兒是京城一等一的大市集
，因為處在城東，人們習慣稱做東市。全國的南北雜貨都要經過這裡，
再由各地的商人轉手運送買賣。所以你可以看到各種景象，有胡人牽馬
來賣的，滿人趕著一車人蔘的，甚麼都有。

LONG);


  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r50",
  "south" : __DIR__"r48",
]) );

  set("gopath", "south" );
  set("objects",([
  "/open/capital/npc/vendor":1,
  ]));

  setup();
}
