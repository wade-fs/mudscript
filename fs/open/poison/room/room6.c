// Room: /open/poison/room/room6
inherit ROOM;

void create ()
{
  set ("short", "前殿");
  set ("long", @LONG
這裡是冥蠱魔教的前殿，內部雕樑畫棟，一片黃彩，殿
內兩旁擺了兩排雕刻精巧的檀木椅，中間則擺了三張華麗的
太師椅，這裡是教內用來接待貴賓和議論教內總總事務的地
方。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road15",
  "north" : __DIR__"road16",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/visitor.c" : 1,
  "/open/poison/npc/greeter" : 1,
]));
  set("light_up",1);

  setup();
}
