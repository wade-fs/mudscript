// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","西大街");
	set( "build", 19 );
  set ("long", @LONG
你正走在刀客的大本營 - 西大街上 . 街上有些衣著華麗的
刀客 , 配戴著黃金小刀 , 那是名滿天下的金刀弟子 . 北邊一
棟華宅 , 應該就是武林三大派之一的金刀門了 ! 聽說金刀門十
分有錢 , 不過 , 從來沒有人知道他們財富的來源 . 往西可以
登上六陽山 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/gblade/room/g1-1",
	"east" : "/open/port/room/r4-2",
]));
	set("objects",([
	"/open/port/npc/trainee":1,
	]));

  setup();
}
