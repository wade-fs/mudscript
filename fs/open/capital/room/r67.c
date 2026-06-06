// Room: /open/capital/room/r67.c

inherit ROOM;

void create ()
{
  set ("short", "中央街口");
	set( "build", 36 );
  set ("long", @LONG
這是一個交叉路口，在你的東邊是扁鵲胡同，是醫者工會所在地,
西邊的文來胡同則是書生工會之所在。如果你對醫生或書生有興趣的話
不妨過去瞧瞧。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r69",
  "north" : __DIR__"r66",
  "west" : __DIR__"h04",
  "east" : __DIR__"h06",
]));
  set("outdoors", "/open/capital");

  setup();
}
