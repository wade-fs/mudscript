//by Casey
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIR"火雲峽"NOR);
  set ("long", @LONG
奮力的穿過窄僅通人的山縫 ,你來到一個全新的
地方。四週了無生機 ,遍地焦土 ,而且處處都有巨大
且深入的爪痕

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
 "out" : __DIR__"d-18",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}


