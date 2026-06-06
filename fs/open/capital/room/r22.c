// Room: /open/capital/room/r22.c

inherit ROOM;

void create ()
{
  set ("short", "豐安橋");
  set ("long", @LONG
白色的大拱橋。橋下的小溪應是流向芙蓉湖的。橋名是當今大宰相
號的，藉此冀求上天賜與國泰民安，百姓豐衣足食。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/capital/room/r21",
  "south" : "/open/capital/room/r23",
]));

  set("gopath", "north");

  setup();
}
