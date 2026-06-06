// Room: /u/p/poloer/dragon/b7
inherit ROOM;

void create ()
{
  set ("short", "炎龍谷中段");
  set ("long", @LONG
四周一點聲音都沒有，反而讓人覺的很恐怖。雜草茂密的讓你看
不到四周的環境，更讓人就像處在暗處一樣，隨時有危險的威脅，不
知隨時可能會命喪這裡。

LONG);
        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"b6",
  "south" : __DIR__"b8",
  "west" : __DIR__"b2",
]));
  set("outdoors", "/u/p");

  setup();
}
