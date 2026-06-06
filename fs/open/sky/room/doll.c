//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW"彩"HIY"靈"HIW"天"HIY"界"NOR);
  set ("long", @LONG
天靈地界中的彩靈天界，數不清的水果香味撲鼻傳來，各種不同
顏色的彩光穿梭縈繞在四周，似真實卻又虛幻的世界中，讓所有見識
到的雙眼都無法轉移焦點，只想多看幾眼，深怕此生再無此機緣得見
此美景。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "west"  : __DIR__"road04",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/magicfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
