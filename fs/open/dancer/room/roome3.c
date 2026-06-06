// Room: /open/dancer/room/roome3.c :cgy
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜夢小築的走廊，北面的牆上有著美麗的雕塑，走到這裡你聞到
陣陣花香，東面就是月牙兒的寢室，南面則是花園，如果沒事的話還
是不要隨便進入寢室吧!!

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/dancer/room/roome2.c",
  "east" : "/open/dancer/room/roome4.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));

  create_door("east", MAG + "鏤花紅檜大門" + NOR, "west", DOOR_CLOSED);
  set("light_up", 1);

  setup();
}
