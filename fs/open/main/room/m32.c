// Room: /open/main/room/m32.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set( "build", 60 );
	set("long", "離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的西方.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m24",
  "south" : __DIR__"f19",
  "west" : __DIR__"r34",
  "east" : __DIR__"f17",
]) );

  set("outdoors", "/open/main" );
  setup();
}
