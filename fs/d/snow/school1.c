// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 淳風武館大門");
  set ("long", @LONG
你現在正站在一間大宅院的入口﹐兩隻巨大的石獅鎮守在大門的兩
側﹐一陣陣吆喝與刀劍碰撞的聲音從院子中傳來﹐通過大門往東可以望
見許多身穿灰衣的漢子正在操練。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 1,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mstreet1",
  "east" : __DIR__"school2",
]));

  setup();
}
