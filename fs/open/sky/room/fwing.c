//crystal.c
//敘述設計by evilsword, code by blazakira 2011/8/21

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW"自由天界"NOR);
  set ("long", @LONG
天靈地界中的羽靈天界，無數的羽毛狀的符籙從這裏的每一個角
落飄落而下，ㄧ踏入此地便被一股莫名的威壓壟罩，令人感到無比的
束縛，似乎整個人被這龐大的封印連同封印石ㄧ同鎮壓著。

LONG);

  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east"  : __DIR__"road05",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/fwingfon.c" : 1,
  ]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
    "designer" : "敘述設計by evilsword, code by blazakira 2011/8/17",
  ]));
  setup();
}
