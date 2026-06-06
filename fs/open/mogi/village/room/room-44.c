//room:/u/e/eva/village/room/room-44.c        made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create ()
{
  set ("short", "魔界村民房");
  set ("long", @LONG

    一間用磚瓦砌成的普通民房, 屋內放置一些簡單的家具擺設, 是
魔界村中的標準住宅!

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/mogi/village/npc/s_woman_b" : 1,
  "/open/mogi/village/npc/s_man_b" : 1,
]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room-07",
]));
  set("no_fight", 1);
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
