// Room: /open/capital/room/g1
inherit ROOM;

void create ()
{
  set ("short", "幽暗的密道");
  set ("long", @LONG
隧道延伸到這裡, 前頭的亮光越發顯的明亮, 隱隱約約的看過去,
好似是一棟石室的樣子, 你手上的持的亮光搖搖晃晃的, 映的你的身影
也搖曳不定。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"q0",
  "east" : __DIR__"q2",
]));
  set("no_transmit", 1);

  setup();
}
