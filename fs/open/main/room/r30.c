// Room: /open/main/room/r30.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 36 );
  set ("long", @LONG
你走在灰塵滾滾的石子路上，望著四週空蕩的丘陵與盆地，
是如此的孤獨與沉寂，北方有一條官道，往南，則可到平南城
，那裡已經進遠離中土，接近苗疆了.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"m15",
  "north" : __DIR__"r23",
  "south" : __DIR__"r32",
  "east" : __DIR__"m16",
]));

  set("outdoors", "/open/main");


  setup();
}
