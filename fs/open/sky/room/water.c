//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIC"水靈天界"NOR);
  set ("long", @LONG
天靈地界中的水靈天界，藍色的水光從這裏的每一個角落透出，
一片淡藍色的世界裏，令人感到心境愉快，忍不住想在這奇幻的天界
中多待一會。

LONG);

  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east"  : __DIR__"road02",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/waterfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
