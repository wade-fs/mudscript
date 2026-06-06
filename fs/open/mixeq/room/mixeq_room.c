#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "怪草廬");
  set ("long", "
一來到這裡，可以感覺到明顯的不同，除了常見的草木以外，你看到了一些
以前從未看到過的東西，還有一個穿著奇裝異服的人。
\n"
);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/nolayer":1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north": __DIR__"room001",
]));
  set("light_up", 1);

  setup();
}
