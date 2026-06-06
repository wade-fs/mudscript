//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIY"金靈天界"NOR);
  set ("long", @LONG
天靈地界中的金靈天界，金色的光茫從這裏的每一個角落透出，
一片金黃色的世界裏，令人感到心境愉快，忍不住想在這奇幻的天界
中多待一會。

LONG);

  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east"  : __DIR__"road01",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/goldfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
