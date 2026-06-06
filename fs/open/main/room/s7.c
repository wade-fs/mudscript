// Room: /open/main/room/s7.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 24 );
  set ("long", @LONG
這裡是一望無際的大草原，地上有不少野獸的足跡
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/sparrow" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L1",
  "west" : __DIR__"s4",
  "north" : __DIR__"s5",
  "east" : __DIR__"s8",
]));

  setup();
}
