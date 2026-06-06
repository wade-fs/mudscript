// Room: /open/main/room/s38.c

inherit ROOM;

void create()
{
	set("short","道路");
	set( "build", 48 );
	set("long",
"這是一條青石板鋪成的道路 , 是朝廷近年來所造 , 道路向
南北延伸 , 連接著中央驛站和大陸唯一的港口 -- 楓林港 . 近幾
年來由於和其他大陸的通航 , 楓林港早已從原本樸素的小鄉村一
躍而成為王朝商業重鎮 , 南方就是楓林港的北門 .

");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s31",
  "west" : __DIR__"s37",
  "east" : __DIR__"s39",
	"south" : "/open/port/room/r1-1",
]) );

  set("outdoors", "/open/main" );

  setup();
}
