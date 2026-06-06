// Room: /u/p/poloer/dragon/b8
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷");
  set ("long", @LONG
四周一點聲音都沒有，反而讓人覺的很恐怖。雜草茂密的讓你看
不到四周的環境，更讓人就像處在暗處一樣，隨時有危險的威脅，不
知隨時可能會命喪這裡。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mob4.c" : 1,
]));
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"b9",
  "west" : __DIR__"b5",
  "north" : __DIR__"b7",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
