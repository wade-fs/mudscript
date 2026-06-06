// Room: /open/main/room/r33.c

inherit ROOM;

void create ()
{
	set("short","道路");
	set( "build", 60 );
  set ("long", @LONG
順著道路走 , 你登上了一座丘陵 , 南方是一片森林 , 從這裡
你可以清楚的看到北邊的中央驛站 , 人來人往 , 好不熱鬧 .

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"m26",
  "north" : __DIR__"r31",
  "south" : __DIR__"r35",
]));

  set("outdoors", "/open/main");

  setup();
}
