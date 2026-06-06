// Room: /u/p/poloer/dragon/g5
inherit ROOM;

void create ()
{
  set ("short", "魔王殿一樓");
  set ("long", @LONG
這裡是魔王殿的一樓，裡面一片烏黑黑的，伸手不見五指，怪恐怖
的。不時還傳來怪物的叫聲。

           ～嘿 ～嘿　～

LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"g51",
  "east" : __DIR__"g4",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
