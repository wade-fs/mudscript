// Room: /u/f/fire/room/room1-15.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
看著古色古香的長沙街道，整條街道全是由大青石花紋板所鋪成
，相當平整且寬敞，街頭人來人往好不熱鬧，兩旁的店舖，小販叫賣
聲音更是為這街道增添不少活力。
LONG);

  set("objects", ([ /* sizeof() == 1 */
C_NPC"/woman" : 1,
]));
set("outdoors","/open/marksman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-9",
  "east" : __DIR__"room1-16.c",
]));

  setup();
}
