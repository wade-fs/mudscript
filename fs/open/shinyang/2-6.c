// Room: /u/w/whatup/area/shinyang/2-6
inherit ROOM;

void create ()
{
  set ("short", "民宅");
  set ("long", @LONG
走進屋子好髒，地上擺滿了頻頻罐罐，四周都是一些奇奇怪的雜
物，難道這是一個資源回收中心？走進去裡面似乎剩下一個人行走的
空間。
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"2-5.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
