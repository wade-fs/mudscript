// Room: /open/main/room/m25.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 12 );
	set("long", "你走上了連綿得土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"f17",
  "west" : __DIR__"m24",
  "north" : __DIR__"m17",
  "east" : __DIR__"m26",
]) );

  set("outdoors", "/open/main" );


  setup();
}
