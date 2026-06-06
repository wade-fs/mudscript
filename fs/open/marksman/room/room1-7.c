// Room: /u/f/fire/room/room1-7.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
你走在這長長大大的長沙道上，只感覺這的風景十分美麗，風兒
輕輕的往你的臉龐吹動，似乎把你烏黑的秀髮吹散。你看到長沙城的
民眾是否都在閒逛著，顯示出沒有戰爭的和平城鎮。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/girl" : 1,
]));
  set("outdoors", "/u/f");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-4",
  "east" : __DIR__"room1-10.c",
]));

  setup();
}
