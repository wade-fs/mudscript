// Room: /open/main/room/m30.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 24 );
	set("long", "你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L11",
  "north" : __DIR__"m21",
  "west" : __DIR__"m29",
  "east" : __DIR__"m31",
]) );

  set("outdoors", "/open/main" );


  setup();
}
