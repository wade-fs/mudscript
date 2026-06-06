// Room: /open/main/room/r10.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 110 );
	set("long", "這裡是從驛站通往北盧關必經的要道, 東邊是一片樹林, 西邊則是
一座高高聳立的山頭，是道教的發源地崑崙山。
");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r12",
  "north" : __DIR__"r7",
  "east" : __DIR__"f11",
]) );

  set("outdoors", "/open/main" );


  setup();
}
