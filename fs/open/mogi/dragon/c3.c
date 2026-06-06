// Room: /u/p/poloer/dragon/c3
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷後段");
  set ("long", @LONG
來到了後段就必須更加小心，也就是越靠近兇惡的谷主囉。四周
突然比較有生氣起來，可以看到些小動物了，但不禁懷疑這是誘敵的
技巧嗎?

LONG);

  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"c1",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
