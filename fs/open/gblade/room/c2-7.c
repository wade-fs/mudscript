inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

四周盡是一片漆黑，即使手中有火把，仍然看不太清楚四周的環境，你只
好靠著牆壁摸索前進。突然前方傳來一陣獸吼，把你嚇了一大跳，不知道
是什麼樣的野獸竟然能發出如此的巨響。

LONG);

  set("light_up",0);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"c2-6.c",
  "east" : __DIR__"c2-8.c",
]));

  setup();
}
