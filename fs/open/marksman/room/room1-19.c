// Room: /u/f/fire/room/room1-19.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "長沙道");
  set ("long", @LONG
夕陽餘日暉從古老的樅樹間照射進來，細碎的石子所鋪成的道路
，兩旁盡是樹林，在樹下開滿了喜歡陰涼的花朵，微風輕輕的從樹林
裡吹拂過來，樹葉猶如被風捉弄一般生氣的發出沙沙沙的聲音。
LONG);

  set("outdoors", "/open/marksman");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"proom1.c",
  "south" : __DIR__"room1-20.c",
  "west" : __DIR__"room1-16.c",
]));

  setup();
}
