// Room: /open/soulin/room/s07.c

inherit ROOM;

void create ()
{
  set ("short", "穿堂");
  set ("long", @LONG

一條長長的走廊，直直通往最著名的大雄寶殿。左右兩邊分別
通往羅漢堂及戒律堂。


LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"big.c",
  "west" : __DIR__"s14.c",
  "east" : __DIR__"s08.c",
  "south" : __DIR__"s42.c",
]));
  set("light_up", "1");
  set("build", 12);

  setup();
}
