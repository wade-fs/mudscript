// Room: /open/main/room/r36.c

inherit ROOM;

void create ()
{
  set ("short", "黃土小路");
	set( "build", 12 );
  set ("long", @LONG
這是一條人煙稀少的小路，彎彎曲曲的往南走，誰也不知到
最後它會通往那裡，只知到有一個傳說中的關卡海山關，在遙遠
的天的那一方. 道路呈東西走向.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f23",
  "west" : __DIR__"r35",
  "east" : __DIR__"r37",
]));

  set("outdoors", "/open/main");

  setup();
}
