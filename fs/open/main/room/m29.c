// Room: /open/main/room/m29.c

inherit ROOM;

void create()
{
	set("short", "丘陵");
	set("long", "你走上了連綿的土丘,微微的風輕拂著你,這裡甚麼都沒有,
有著只是茫茫的蘆花和藍天.
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L10",
  "west" : __DIR__"m28",
  "north" : __DIR__"m20",
  "east" : __DIR__"m30",
]) );

  set("outdoors", "/open/main" );


  setup();
}
