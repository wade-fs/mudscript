// Room: /open/main/room/m24.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 72 );
	set("long", "離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的西方.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m16",
  "west" : __DIR__"r32",
  "south" : __DIR__"m32",
  "east" : __DIR__"m25",
]) );

  set("outdoors", "/open/main" );


  setup();
}
