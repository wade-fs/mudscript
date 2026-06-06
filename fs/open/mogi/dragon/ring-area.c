// Room: /u/p/poloer/dragon/ring-area
inherit ROOM;

void create ()
{
  set ("short", "吊橋邊");
  set ("long", @LONG
來到了山谷旁，那山谷看起來非常的深，如果不小心掉下去可
就沒命了。想要過去可就很困難囉，還好有一座吊橋橫跨山谷可以
幫助我們過去。吊橋旁邊坐著一位人，拿著燈火往四處看著。

LONG);
      set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man.c" : 1,
]));
  set("light_up", 1);
  set("outdoors", "/u/p/poloer/dragon");
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"ring",
  "south" : __DIR__"a10",
]));

  setup();
}
