// Room: /u/g/guetenr/beggar/room/beg1/room2.c
inherit ROOM;

void create ()
{
  set ("short", "平原");
  set ("long", @LONG
你在一片平野上走著, 青青的綠草在散亂的碎石間叢生, 開著五色花朵
的小草堆中, 不時一些小生物爬來爬去。當你走到近處, 它們又紛紛躲進草
叢中。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1.c",
  "north" : __DIR__"room3.c",
]));

  setup();
}
