// Room: /d/snow/eroad2.c

inherit ROOM;

void create ()
{
  set ("short", "過去時空 黃土小徑");
  set ("long", @LONG
這是一條普通的黃土小徑﹐小徑往西南通往一處山間的平地﹐從這
裡可以望見不少房屋錯落在平地上﹐往東北則一路上山。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dog" : 2,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"eroad3",
  "southwest" : __DIR__"eroad1",
]));

  setup();
}
