// Room: /u/w/whatup/area/shinyang/7-7.c
inherit ROOM;

void create ()
{
  set ("short", "萬寶居");
  set ("long", @LONG
這裡是襄陽城中最大的商店，琳瑯滿目的商品，令你目不暇給，
想必你可以在此做最好充分的準備與採購，讓旅途更為平安，當然你
也可以將手中一些無用之物在這裡出售，如同旁邊的掌櫃正與塞外的
牧民交易毛皮呢！
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/child" : 1,
  __DIR__"npc/oldman" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"7-8.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
