// Room: /u/d/dhk/questsfan/rm2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林奇路");
  set ("long", @LONG
一踏入嵩山的土地，就可以感覺到非常舒適、怡然自得
的感覺，一路上薄薄的輕霧，宛若此地靈氣充沛、生機無限
之感，令人不禁感嘆嵩山真不愧貴為五嶽知首呀。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man1.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"rm1",
  "eastup" : __DIR__"rm3",
]));
  set("outdoors", "/u/d");

  setup();
}
