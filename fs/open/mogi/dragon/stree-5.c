// Room: /u/p/poloer/dragon/stree-5
inherit ROOM;

void create ()
{
  set ("short", "樹林");
  set ("long", @LONG
一片廣大的樹林，樹木長的都非常的高聳，而它茂密的葉子，把
陽光都遮住了，使得這裡看起來都暗昏昏的。樹木多的都看不到前方
的路，只能慢慢的前進。

LONG);

  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"key_room",
  "east" : __DIR__"stree-4",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
