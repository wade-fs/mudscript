// Room: /open/main/room/r12.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 36 );
	set("long", "這裡是從驛站通往北盧關必經的要道, 東邊是一片平整的台地
西邊則是高低起伏的丘陵.
");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r19",
  "north" : __DIR__"r10",
  "west" : __DIR__"m7",
]) );

  set("outdoors", "/open/main" );


  setup();
}
