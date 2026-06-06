// Room: /open/capital/room/q0.c
inherit ROOM;

void create ()
{
  set ("short", "幽暗的密道");
  set ("long", @LONG
你可以看到這裡是一條隱密的密道, 兩旁的岩石形成這條天然的隧
道, 岩石上還有涓涓的地下水點點的流下, 「滴答、滴答」的聲音更增
添些許的氣氛, 前方有隱隱的亮光透過來, 糢糢糊糊的看不真切。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"q1",
]));
  set("no_transmit", 1);

  setup();
}
