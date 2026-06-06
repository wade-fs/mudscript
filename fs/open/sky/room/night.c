//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "夜靈天界");
  set ("long", @LONG
天靈地界中的夜靈天界，昏暗的氣息隴罩在四周，一如夜色一樣
的寧靜，令人感到悠然自得，沉浸在這樣的天界中，令人身心舒暢，
忍不住想在這奇幻的天界中多待一會。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "west"  : __DIR__"road03",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/nightfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
