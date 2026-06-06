// Room: /open/main/room/r6.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 30 );
	set("long", "走到這裡,你已漸漸遠離人跡,走在寬廣的蜀州盆地上,卻讓
你有一種蒼茫的感覺,道路在此通向北方或南方,而蜀山,已經在
你北方不遠處.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"r4",
  "south" : __DIR__"r9",
  "west" : __DIR__"m1",
  "east" : __DIR__"F7",
]) );

  set("outdoors", "/open/main" );

  setup();
}
