// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","阜財巷");
  set ("long", @LONG
這裡是阜財巷 , 道路兩旁均是由若干大型廳堂和迴廊所組成
的華宅 , 而且大多有園池之美 , 華宅主人不是從京城退休的高
官 , 就是在楓林致富的巨賈 , 他們大多過著豪奢的生活 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/port/room/r3-6",
]));
	set("objects",([
	]));

  setup();
}
