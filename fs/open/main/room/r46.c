// Room: /open/main/room/r46.c

inherit ROOM;

void create ()
{
  set ("short", "黃土小路");
	set( "build", 24 );
  set ("long", @LONG
這是一條人煙稀少的小路，彎彎曲曲的往南走，誰也不知到
最後它會通往那裡，只知到有一個傳說中的關卡海山關，在遙遠
的天的那一方. 道路往東或往北.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"f28",
  "west" : __DIR__"f26",
  "north" : __DIR__"r45",
  "east" : __DIR__"r47",
]));

  set("outdoors", "/open/main");

  setup();
}
