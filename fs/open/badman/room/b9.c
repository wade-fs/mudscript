// Room: /open/badman/room/b9
inherit ROOM;

void create ()
{
  set ("short", "惡人谷北道街");
  set ("long", @LONG
你發現北街上人群來來往往，似乎比南街熱鬧的多，因為這邊
是惡人谷日常生活的重心，包管全惡人谷的吃喝玩樂。看到人們臉
上輕鬆的表情，你緊繃的神經也稍稍舒緩的下來。或許你可以放鬆
心情好好的逛一逛。
    你聽到東邊的房間傳來陣陣吆喝聲，好像有很多人聚集在那。
    大街往西方和南方延伸。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/rogue" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b10",
  "south" : __DIR__"b8",
  "east" : __DIR__"r5",
]));

  setup();
}
