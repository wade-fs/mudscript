// Room: /open/main/room/m7.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 12 );
  set ("long", @LONG
你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/main/room/F12",
// "north" : "/open/tendo/kunlun/v1",
  "north" : "/open/main/room/M14",
  "west" : "/open/main/room/m6",
  "east" : "/open/main/room/r12",
]));

  set("outdoors", "/open/main");

  setup();
}
