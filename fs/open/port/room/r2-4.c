// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","清風樓客棧");
	set( "build", 20 );
  set ("long", @LONG
這裡是方圓百里內最負盛名的一家客棧 . 許多到楓林來的
商人 , 旅客 , 都指名要來此住宿 . 雖然這裡的客房數量上百
間之多 , 卻仍然一房難求 , 除非你能出的起更高的價錢 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r2-1",
	"up" : "/open/port/room/r2-5",
]));
	set("objects",([
	"/open/port/npc/keeper":1,
	]));

  setup();
}
