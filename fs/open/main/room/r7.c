// Room: /open/main/room/r7.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 24 );
	set("long", "這裡是從驛站通往北盧關必經的要道, 東邊的沼澤地一不小心會把
人整個吞進去, 西邊是一片黑壓壓的密林, 沒事最好別在此處逗留。
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r10",
  "north" : __DIR__"r5",
  "west" : __DIR__"F11",
  "east" : __DIR__"p13",
]) );

  set("outdoors", "/open/main" );

  setup();
}
