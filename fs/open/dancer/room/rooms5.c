// Room: /open/dancer/room/rooms5.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIR"玄關"NOR);
	set( "build", 12 );
  set ("long", @LONG
這裡是夜夢小築的玄關，在這裡有兩個美麗的女子看守，看她們
的模樣似乎弱不禁風，實際上應該是身懷絕技吧。所以沒事的話還是
不要惹她們的好，從這裡可離開夜夢小築，向北則是夜夢小築內部重
心。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/rooms4.c",
  "out" : "/open/dancer/room/dream.c",
]));
 set("objects", ([ /* sizeof() == 1 */
 "/open/dancer/npc/ygirl.c" : 2,
]));

  set("light_up", 1);

  setup();
}
