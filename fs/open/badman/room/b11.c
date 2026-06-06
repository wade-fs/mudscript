// Room: /open/badman/room/b11
inherit ROOM;

void create ()
{
  set ("short", "惡人谷北地街");
  set ("long", @LONG
你發現北街上人群來來往往，似乎比南街熱鬧的多，因為這邊
是惡人谷日常生活的重心，包管全惡人谷的吃喝玩樂。看到人們臉
上輕鬆的表情，你緊繃的神經也稍稍舒緩的下來。或許你可以放鬆
心情好好的逛一逛。

LONG);

   set("objects", ([ /* sizeof() == 1 */
  // "/open/badman/npc/blind.c" : 1,
]));
  set("outdoors", "/open/badman");
   set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b12",
  "east" : __DIR__"b10",
]));

  setup();
}
