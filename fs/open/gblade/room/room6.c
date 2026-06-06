// Room: /u/m/moner/tree/room6.c
inherit ROOM;

void create ()
{
  set ("short", "薜荔蘿林");
  set ("long", @LONG

一大片的薜荔蘿林聳立在你眼前，陣陣的薜荔花香隨風飄送，你的直
覺告訴你不要前進，可是又忍不住內心的好奇。
滿天的彩霞籠罩著天際，一抹夕陽慢慢的消失在地平線。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room7.c",
  "north" : __DIR__"room5.c",
]));

  setup();
}
