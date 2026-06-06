// Room: /u/p/poloer/dragon/bc
inherit ROOM;

void create ()
{
  set ("short", "碎石小路");
  set ("long", @LONG
這是一條不太平整的小路，它是由一些小碎石所鋪設的小路，並
沒有什麼特別之處。不過走到這裡感到非常的恐怖，還是趕快離開吧
。

LONG);

  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bc1",
  "north" : __DIR__"b10",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
