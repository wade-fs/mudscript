// Room: /open/main/room/m8.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 36 );
  set ("long", @LONG
離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的西方或南
方.
LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"m9",
  "west" : __DIR__"r18",
  "north" : __DIR__"m2",
  "south" : __DIR__"r21",
]));
set("no_clean_up", 1);

  setup();
}
