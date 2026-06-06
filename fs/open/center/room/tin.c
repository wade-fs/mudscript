// Room: /u/l/lotus/girl/guest4.c
#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "樓梯口");
  set ("long", @LONG
懸掛了兩個明晃晃的花燈, 煞是好看有一道樓梯通往香樓上小姐
的房間。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tin2.c",
   "south" : __DIR__"tin3.c",
]));

  set("light_up", 1);
  set("file_name", __DIR__"guest4.c");
  setup();
}
