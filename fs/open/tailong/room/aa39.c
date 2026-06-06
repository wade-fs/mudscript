inherit ROOM;

void create ()
{
  set ("short", "大雄寶殿");
  set ("long", @LONG
這裡是大雄寶殿的正中心,在你的面前那一位慈眉善目的老和尚
就是天龍寺中的本因方丈,看他一副和藹可親的模樣,相信常人絕對
想不到他是一個武林高手。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"aa38",
  "south" : __DIR__"aa36",
  "north" : __DIR__"aa42",
  "east" : __DIR__"aa40",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/tailong/npc/inn.c" : 1,
]));

  setup();
  replace_program(ROOM);
}
