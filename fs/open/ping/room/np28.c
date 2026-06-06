#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "玄關");
  set ("long", @LONG
長長的走道向前延伸, 北邊有一間房間, 正是段雲獨生女～段小詩～
的閨房, 你聞到房中傳出的香氣, 不禁心神俱醉。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"np29",
  "east" : __DIR__"np24",
]));
  set("light_up", 1);

  setup();
}
