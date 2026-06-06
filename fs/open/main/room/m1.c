// Room: /open/main/room/m1.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 34 );
  set ("long", @LONG
離開了道路,你走上了一座土丘,微微的風輕拂著你,這裡甚
麼都沒有,有著只是茫茫的蘆花和藍天. 道路則在你的南方或東
方.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/butterfly" : 1,
  "/obj/source/faint":2,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"f9",
  "south" : __DIR__"r8",
  "east" : __DIR__"r6",
]));

  setup();
}
