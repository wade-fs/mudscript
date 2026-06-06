// Room: /open/poison/room/snake_hole.c
inherit ROOM;

void create ()
{
  set ("short", "山洞深處");
  set ("long", @LONG
這裡是山洞的深處, 處處爬滿了不同的毒蛇, 可說是
一個名幅其實的蛇洞。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"snake_hole2",
  "out" : __DIR__"cave3",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/bigsnake.c" : 1,
]));

  setup();
}
