// Room: /open/badman/room/b13
inherit ROOM;

void create ()
{
  set ("short", "惡人谷北法街");
  set ("long", @LONG
你發現北街上人群來來往往，似乎比南街熱鬧的多，因為這邊
是惡人谷日常生活的重心，包管全惡人谷的吃喝玩樂。看到人們臉
上輕鬆的表情，你緊繃的神經也稍稍舒緩的下來。或許你可以放鬆
心情好好的逛一逛。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"b7",
  "north" : __DIR__"b12",
]));
  set("outdoors", "/open/badman");

  setup();
}
