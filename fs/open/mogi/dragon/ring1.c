// Room: /u/p/poloer/dragon/ring1
inherit ROOM;

void create ()
{
  set ("short", "吊橋上");
  set ("long", @LONG
  走上了吊橋，橋身搖搖晃晃的站的站不穩，好
  像快要掉下去一樣，如果不小心掉下去那可不得了
  。還是加緊腳步快走吧。

           ～ 吊橋的繩索喀喀的響～

LONG);
      set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);

  set("no_magic", 1);
  set("outdoors", "/u/p/poloer/dragon");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ring2",
  "south" : __DIR__"ring",
]));
  set("no_fight", 1);

  setup();
}
