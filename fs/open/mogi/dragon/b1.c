// Room: /u/p/poloer/dragon/b1
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷中段");
  set ("long", @LONG
來到了這裡，四周看起來更加的詭異，有點想退縮的感覺。
這裡的殺氣很重，讓人感覺到非常的難過，同時也感覺到很想殺
人。周圍盡是一些死人的駭骨，使人不禁退後三步。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mob4.c" : 2,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"b4",
  "up" : __DIR__"ring3",
  "south" : __DIR__"b2",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
