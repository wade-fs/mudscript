// Room: /open/dancer/room/roomse2.c :cgy
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIC"噴水池"NOR);
  set("long", @LONG
一個別致幽雅的噴水池，這個水池的水源來自於鏡月島底下的自
湧泉，長年有泉水供應，你可以在此裝水(fill)，或是在此飲水，而
在這個風景幽雅的地方休息也是一件舒服的事。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"roomse3.c",
  "west" : __DIR__"roomse1.c",
  "north" : __DIR__"roomes2.c",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/obj/pool" : 1,
]));
  setup();
}
