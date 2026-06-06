// Room: /open/dancer/room/rooms3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIC"練舞場"NOR);
  set( "build", 12 );
  set ("long", @LONG
這裡是夜夢小築的練舞(武)場，在此你可以看到許多弟子們生澀
的舞姿，當然也可以看到先進弟子們曼妙優雅的舞姿，所有的夜夢弟
子們都是在此練習技能的，因此這裡也成了眾弟子研究討論之所。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : "/open/dancer/room/roomse1.c",
  "west" : "/open/dancer/room/roomsw1.c",
  "north" : "/open/dancer/room/rooms2.c",
  "south" : "/open/dancer/room/rooms4.c",
]));
 set("objects", ([ /* sizeof() == 1 */
 "/open/dancer/npc/rgirl.c" : 2,
]));
  set("light_up", 1);
  setup();
}
