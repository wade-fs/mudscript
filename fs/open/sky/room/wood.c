//排版 by blazakira 2011/8/4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIG + "木靈天界" + NOR);
  set ("long", @LONG
天靈地界中的木色天界，濃郁的各種天然木香從這個天界裏散發
出來，沉浸在這樣的天界中，令人身心舒暢，忍不住想在這奇幻的天
界中流連忘返。

LONG);
  set("no_auc", 1);
  set("no_transmit", 1);
  set("no_chome", 1);
  set("exits", ([ /* sizeof() == 1 */
    "west"  : __DIR__"road01",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/sky/stone/woodfon" : 1,
  ]));
  set("light_up", 1);
  setup();
}
