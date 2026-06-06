inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "長白山腰");
  set ("long", @LONG
歷盡長途拔涉，你已經來到了長白山的半山腰了，環看遠方，你
已經有種登高的感覺，慢慢的你如深陷於雲海之中，漸漸看不清遠方
的山，雲氣慢慢的向你聚集而來，讓你想快快開這裏。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fox.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"mon20",
  "north" : __DIR__"mon22",
]));

  setup();
}
