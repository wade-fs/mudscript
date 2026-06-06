//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIB + "晶靈天界" + NOR);
  set ("long", @LONG
天靈地界中的晶靈天界，黃色與紅色的晶石光彩漫布在這個空間
中，一片的奇幻讓你看的目瞪口呆，晶光流舞，炫彩奪目，已令渾然
忘我。

LONG);

  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east"  : __DIR__"road04",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/crystalfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
