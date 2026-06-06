// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
	set( "build", 12 );
  set ("long", @LONG
這裡是楓林港的中央大街 . 原本的楓林只是個貧窮的小漁村
 , 在十餘年前建立港口後 , 因為海運的發達帶動了商業的繁榮 
. 近年來的快速發展正展示出楓林旺盛的生機 . 這是一座不斷擴
張的城市 . 西邊是一家錢莊 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/port/room/r1-1",
	"south" : "/open/port/room/r1-3",
	"west" : "/open/port/room/r1-5",
	"east" : "/open/port/room/r6-1",
]));
	set("objects",([
	]));

  setup();
}
