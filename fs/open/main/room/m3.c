// Room: /open/main/room/m3.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 24 );
  set ("long", @LONG
你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/junkman.c" : 2,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"m2",
  "south" : __DIR__"m9",
  "east" : __DIR__"m4",
]));

  setup();
}
