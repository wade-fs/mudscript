// Room: /u/d/dhk/questsfan/rm4
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林" + HIC + "翗" + NOR + "路");
  set ("long", @LONG
這一段路上，竟讓你看到一隻身形好像鳳凰而其全身都
是碧綠色的不知名的鳥。而且牠在飛翔之迅速、優美，令人
讚嘆。也因為這樣的奇遇促使你對這一段路更好奇，繼續的
探險下去。

LONG);

  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"rm3",
  "eastup" : __DIR__"rm5",
]));

  setup();
}
