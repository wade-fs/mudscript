// Room: /open/main/room/r20.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 12 );
  set ("long", @LONG
	這條道路直往南北延伸，往東方的草原望去
	可以看到一座大城，西方的視線被台地所阻隔
	但隱約的看到在台地上似乎有座山。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r29",
  "north" : __DIR__"r13",
  "east" : __DIR__"s15",
]));

  set("outdoors", "/open/main");

  setup();
}
