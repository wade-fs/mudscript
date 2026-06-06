// Room: /open/main/room/m9.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 60 );
  set ("long", @LONG
離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的南方.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/wolf" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"m8",
  "north" : __DIR__"m3",
  "south" : __DIR__"r22",
  "east" : __DIR__"m10",
]));

  setup();
}
