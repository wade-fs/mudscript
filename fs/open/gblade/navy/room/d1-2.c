// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","石板大道");
	set( "build", 60 );
  set ("long", @LONG
你正走在一條又寬又平坦的石板大道上 . 道路通往本國唯一
的水軍基地 . 這一帶是軍事重地 , 普通的民眾是不能隨意通行
的 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/gblade/navy/room/d1-1.c",
	"east" : "/open/gblade/navy/room/d1-3.c",
]));
	set("objects",([
	]));

  setup();
}
