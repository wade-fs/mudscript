// Room: /open/main/room/r45.c

inherit ROOM;

void create ()
{
  set ("short", "黃土小路");
	set( "build", 36 );
  set ("long", @LONG
這是一條人煙稀少的小路，彎彎曲曲的往南走，誰也不知到
最後它會通往那裡，只知到有一個傳說中的關卡海山關，在遙遠
的天的那一方. 道路呈南北走向.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r46",
  "north" : __DIR__"r40",
  "west" : __DIR__"f25",
  "east" : __DIR__"L19",
]));

  set("outdoors", "/open/main");

  setup();
}
