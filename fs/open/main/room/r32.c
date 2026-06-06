// Room: /open/main/room/r32.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 24 );
  set ("long", @LONG
你走在灰塵滾滾的石子路上，望著四週空蕩的丘陵與盆地，
是如此的孤獨與沉寂，也許這就是身入江湖的悲哀吧..道路在此
呈南北走向，越往南則越遠離中土，越近苗疆.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r34",
  "north" : __DIR__"r30",
  "west" : __DIR__"m23",
  "east" : __DIR__"m24",
]));

  setup();
}
