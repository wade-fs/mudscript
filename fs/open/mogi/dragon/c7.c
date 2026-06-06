// Room: /u/p/poloer/dragon/c7
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷後段");
  set ("long", @LONG
來到了後段就必須更加小心，也就是越靠近兇惡的谷主囉。四周
突然比較有生氣起來，可以看到些小動物了，但不禁懷疑這是誘敵的
技巧嗎?

LONG);

  set("evil", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"c5",
  "south" : __DIR__"c9",
  "east" : __DIR__"c9",
]));
  set("outdoors", "/u/p");
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mob8.c" : 2,
  __DIR__"npc/mob7.c" : 2,
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
