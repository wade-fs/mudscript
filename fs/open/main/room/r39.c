// Room: /open/main/room/r39.c

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

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"L15",
  "south" : __DIR__"r43",
  "north" : __DIR__"r34",
  "east" : __DIR__"f19",
]));

  set("outdoors", "/open/main");

  setup();
}
