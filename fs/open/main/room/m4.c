// Room: /open/main/room/m4.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 48 );
	set("long", "你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"m10",
  "west" : __DIR__"m3",
  "east" : __DIR__"m5",
]) );

  set("outdoors", "/open/main" );


  setup();
}
