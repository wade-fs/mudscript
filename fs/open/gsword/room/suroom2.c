// Room: /open/gsword/room/suroom2.c

inherit ROOM;

void create ()
{
  set ("short", "四海刀聯");
  set ("long", @LONG
本總部因感於身在劍士充斥的蜀中招生困難
於辛亥年十月十日將總部移往楓林港
不便之處 , 敬請包涵體諒

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"su11",
]));
  set("light_up", 1);

  setup();
}
