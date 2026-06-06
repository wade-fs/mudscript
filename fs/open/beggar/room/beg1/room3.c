// Room: /u/g/guetenr/beggar/room/beg1/room3.c
inherit ROOM;

void create ()
{
  set ("short", "平原");
  set ("long", @LONG
你在一片平野上走著，青青的綠草在散亂的碎石間叢生，開著五色花朵
的小草堆中，不時一些小生物爬來爬去。當你走到近處，它們又紛紛躲進草
叢中，看不出到底有那些生物。但說也奇怪，無論你如何尋找，總是只聞其
聲，不見其影，漸漸地，一絲莫名的恐懼爬上心頭。

LONG);

  set("outdoors", "/u/g");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room2.c",
  "north" : __DIR__"room4.c",
]));

  setup();
}
