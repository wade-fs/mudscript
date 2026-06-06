// Room: /open/main/room/m26.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 37 );
	set("long", "離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的東方.
");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f18",
  "west" : __DIR__"m25",
  "east" : __DIR__"r33",
]) );

  set("outdoors", "/open/main" );


  setup();
}
