inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "登山小徑");
  set ("long", @LONG
愈往前走，路愈是難走，前面的路已經愈來愈小條了，若非懷著
絕世輕功的人走上這條路將會倍感吃力，但通往山上的小路依舊清楚
可見。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mon11",
  "west" : __DIR__"mon08",
]));

  setup();
}
