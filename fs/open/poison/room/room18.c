// Room: /open/poison/room/room18
inherit ROOM;

void create ()
{
  set ("short", "魔殿側殿");
  set ("long", @LONG
這裡是冥蠱魔殿的側殿，這裡連同正殿，擺設許多奇珍
異寶，大殿內由大夜明珠裝飾而成的巨火神像發出瑞彩的光
芒，整個魔殿沉浸在一片光彩之中。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room1",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/left_hufa.c" : 1,
]));
  set("light_up", 1);

  setup();
}
