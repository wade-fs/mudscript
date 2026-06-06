// Room: /open/main/room/s31.c

inherit ROOM;

void create()
{
	set("short","道路");
	set( "build", 24 );
	set("long",
"這是一條青石板鋪成的道路 , 似乎剛鋪好不久似的 , 道路向
南北延伸 , 連接著中央驛站和大陸唯一的港口 -- 楓林港 . 你看到
絡繹不絕的旅客和商隊行走於路上 ,一片欣欣向榮 .

");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"s27",
	"south" : __DIR__"s38",
  "west" : __DIR__"s30",
  "east" : __DIR__"s32",
]) );

  set("outdoors", "/open/main" );

  setup();
}
