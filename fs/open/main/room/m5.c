// Room: /open/main/room/m5.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 36 );
	set("long", "你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"m4",
  "south" : __DIR__"m11",
  "east" : __DIR__"m6",
]) );

  set("outdoors", "/open/main" );


  setup();
}
