// Room: /u/p/poloer/dragon/stree
inherit ROOM;

void create ()
{
  set ("short", "樹林");
  set ("long", @LONG
一片廣大的樹林，樹木長的都非常的高聳，而它茂密的葉子，把
陽光都遮住了，使得這裡看起來都暗昏昏的。樹木多的都看不到前方
的路，只能慢慢的前進。

LONG);
        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"a6",
  "east" : __DIR__"stree-1",
]));
  set("outdoors", "/u/p");

  setup();
}
