// Room: /u/g/guetenr/beggar/room/beg1/room7.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
地上鋪著石版﹐整個小路看起來漸漸有了京城的規模﹐陸上行人也變得
越來越多。你走在路上﹐不時回頭張望﹐最近真的是小偷越來越。路上的小
乞兒不時望著你﹐希望你能賞點銅錢給他們。
LONG);

  set("outdoors", "/u/g");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room8.c",
  "east" : __DIR__"room5.c",
  "south" : __DIR__"room9.c",
]));

  setup();
}
