// Room: /open/capital/room/r54.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
從這裡開始，都是達官貴人們的住所了，所以閒雜的人是不能在此
逗留的，在此進出的都是些有權有勢的人。看著兩旁的屋宇豪華, 你心
中不禁十分憧憬做官的威風起來。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/r19",
  "east" : "/open/capital/room/r55",
]));

  set("outdoors", "/open/capital");

  setup();
}
