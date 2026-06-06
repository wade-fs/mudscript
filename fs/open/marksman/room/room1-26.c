// Room: /u/f/fire/room/room1-26.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
  set ("long", @LONG
一條用潔白如雪的石磚所鋪所的走道，兩旁的花園，一眼望去皆
是朵朵嬌麗的花兒，鼻中所聞到的儘是芬芳的氣息，左右兩旁的柱子
雕刻著美麗的紋路，圍繞柱子的薔薇開滿了釵h的花朵。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room1-28.c",
  "east" : __DIR__"room1-23",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman" : 2,
]));

  setup();
}
