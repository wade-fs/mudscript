// Room: /open/main/room/r35.c

inherit ROOM;

void create ()
{
	set("short","道路");
	set( "build", 24 );
  set ("long", @LONG
道路在此貫穿了一片原始森林 , 不時有些小猴子會跑到路上
來 , 真逗趣 , 一條黃土小徑往東接去 , 不知通往何處 , 道路
繼續往南北延伸 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"f22",
  "west" : __DIR__"f18",
  "north" : __DIR__"r33",
  "east" : __DIR__"r36",
]));

  set("outdoors", "/open/main");

  setup();
}
