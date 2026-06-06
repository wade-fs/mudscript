// Room: /open/main/room/r41.c

inherit ROOM;

void create ()
{
  set ("short", "黃土路");
  set ("long", @LONG
這是一條東西向的道路,往東是平南城,往西則進入苗疆.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"maiu-1.c",
  "north" : __DIR__"L13",
  "east" : "/open/ping/room/wdoor",
]));
  set("outdoors", "/open/main");

  setup();
}
