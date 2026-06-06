// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
	set("short","史家商店");
	set( "build", 19 );
  set ("long", @LONG
這裡是楓林港最大的商店 . 物品的數量之多 , 種類之豐 , 
在全國都是首屈一指的 . 這家店的老闆是本地的大鹽商史懷恩 ,
 現在由他的三兒子史貴負責打理 . 你可以看看這裡有些甚麼(list)
交易(buy) , 還有估價(value) .
也可以看看這裡有賣那些種類的東西(view)
LONG);

  set("exits", ([ /* sizeof() == 1 */
	"east" : "/open/port/room/r1-4",
]));
  set("light_up", 1);

  setup();
}
