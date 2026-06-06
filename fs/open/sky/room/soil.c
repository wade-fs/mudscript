//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", YEL"土靈天界"NOR);
  set ("long", @LONG
天靈地界中的土靈天界，褐色的沙影從這裏的每一個角落飛出，
一片褐黃色的世界裏，感到一陣詳和愉快，忍不住想在這奇幻的天界
中多待一會。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east"  : __DIR__"road03",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/soilfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
