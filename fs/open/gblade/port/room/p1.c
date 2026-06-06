// Room: /open/gblade/port/room/p1.c
inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
這是一條青石板鋪成的道路 , 是朝廷近年來所造 , 道路向
南北延伸 , 連接著中央驛站和大陸唯一的港口 -- 楓林港 . 近幾
年來由於和其他大陸的通航 , 楓林港早已從原本樸素的小鄉村一
躍而成為王朝商業重鎮 , 南方就是楓林港的北門 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/main/room/s38.c",
  "south" : __DIR__"p1-1",
]));

  setup();
}
