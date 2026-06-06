// Room: /open/badman/room/tigerhole
inherit ROOM;

void create ()
{
  set ("short", "虎穴");
  set ("long", @LONG
你終於來到了地道的盡頭，四周斑斑的血跡和吃剩的動物屍體
，原來這竟是森林之王－老虎的巢穴，看來此地還是不宜久留，趕
快離開的好。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/badman/room/t7",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/s_tiger" : 1,
]));

  setup();
}
