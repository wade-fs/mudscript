// Room: /u/d/dhk/questsfan/rm7
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林"HIY"跂"NOR"路");
  set ("long", @LONG
你越爬越高，而四周的霧也越來越濃，這好像意味著周
圍的危險性相對也越來越高。四周傳來令人驚聳的響聲。
 ───沙沙───   ─《吼》─   ───沙沙─── 

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"rm8.c",
  "eastdown" : __DIR__"rm6",
]));
  set("outdoors", "/u/d");

  setup();
}
