// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","客棧二樓");
	set( "build", 12 );
  set ("long", @LONG
這裡是清風樓客棧的二樓 . 西面和南面是挖空的 , 分別搭
了個陽台 . 你可以直接從這裡看到海港 , 每到夏天 , 海風徐
徐吹來 , 在此小坐 , 甚為舒爽 . 城裡的人最喜歡來此乘涼 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"down" : "/open/port/room/r2-4",
]));
	set("objects",([
	]));

  setup();
}
