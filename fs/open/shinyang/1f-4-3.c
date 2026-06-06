// Room: /u/w/whatup/area/shinyang/1f-4-3.c
inherit ROOM;

void create ()
{
  set ("short", "樓梯口");
  set ("long", @LONG
這個地方黑呼呼的，不知道通往哪裡，不時重漆黑的門口中傳來
陣陣的哀嚎聲與鞭打聲，四周的衛兵比其他地方多了一倍，想必這裡
是城中地牢的人口，關著一些汪洋大盜跟通緝犯，想了想還是不要靠
近的好。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 5 */
  "down" : __DIR__"b1-1.c",
  "north" : __DIR__"1f-4-4.c",
  "west" : __DIR__"1f-3-3.c",
  "east" : __DIR__"1f-5-3.c",
  "south" : __DIR__"1f-4-2.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
