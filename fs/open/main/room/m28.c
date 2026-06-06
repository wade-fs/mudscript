// Room: /open/main/room/m28.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 36 );
	set("long", "你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L9",
  "west" : __DIR__"m27",
  "north" : __DIR__"m19",
  "east" : __DIR__"m29",
]) );

  set("outdoors", "/open/main" );


  setup();
}
