// Room: /open/main/room/r5.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 66 );
  set ("long", @LONG
這裡是從驛站通往北盧關必經的要道, 東邊的沼澤地一不小心會把
人整個吞進去, 西邊有一塊平地, 看起來毫不起眼.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r7",
  "west" : __DIR__"L4",
  "east" : __DIR__"p7",
]));
  set("outdoors", "/open/main");

  setup();
}
