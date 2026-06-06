// Room: /open/main/room/m17.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 24 );
  set ("long", @LONG
離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的北方.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/bear" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r25",
  "south" : __DIR__"m25",
  "west" : __DIR__"m16",
]));

  setup();
}
