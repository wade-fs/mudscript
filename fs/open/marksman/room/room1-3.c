// Room: /u/f/fire/room/room1-3.c
#include "marksman.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", GRN"長沙道"NOR);
  set ("long", @LONG
你來到了一個雙叉廣場，無數的民眾正向著一些小攤販買著一些
家庭所需要的物品。長沙城的風景十分美麗，一陣陣的飄風飄來了一
陣陣的花香，花香往你的臉頰而來。
LONG);

  set("objects", ([ /* sizeof() == 2 */
C_NPC"/woman" : 1,
C_NPC"/oldwoman" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-2.c",
  "north" : __DIR__"room1-8.c",
  "east" : __DIR__"room1-4.c",
"west" : __DIR__"room1-34",
]));

  setup();
}

