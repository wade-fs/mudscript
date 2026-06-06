// Room: /open/poison/room/room8
inherit ROOM;

void create ()
{
  set ("short", "執法堂");
  set ("long", @LONG
這裡是冥蠱魔教用以審判教眾的地方，廳堂中間有一浮
雕精細的太師椅，太師椅上坐著一位雙眼炯炯有神的老者，
他便是此魔教的執法大長老，在他的魔掌之下，所有觸犯教
規的教徒一一伏法就刑，無一幸免。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/poison/room/room10",
  "north" : "/open/poison/room/room9",
  "west" : "/open/poison/room/road17",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/elder2" : 1,
]));

  set("light_up", 1);

  setup();
}
