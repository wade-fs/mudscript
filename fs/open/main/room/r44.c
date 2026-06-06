// Room: /open/main/room/r44.c

inherit ROOM;

void create ()
{
  set ("short", "石子小路");
	set( "build", 12 );
  set ("long", @LONG
這是一條小小的石子小徑，不仔細搜尋，你還不知道有這
，道路通往東西方，可是誰也不曉得它往那走.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L25",
  "west" : __DIR__"r43",
  "north" : __DIR__"f19",
	"east":"/open/main/room/[3]",
]));
  set("outdoors", "/open/main");

  setup();
}
