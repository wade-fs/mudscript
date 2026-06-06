// Room: /open/main/room/r40.c

inherit ROOM;

void create ()
{
  set ("short", "黃土小路");
	set( "build", 24 );
  set ("long", @LONG
這是一條人煙稀少的小路，彎彎曲曲的往南走，誰也不知到
最後它會通往那裡，只知到有一個傳說中的關卡海山關，在遙遠
的天的那一方. 道路呈南北走向.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"f24",
  "north" : __DIR__"r38",
  "south" : __DIR__"r45",
  "east" : __DIR__"L16",
]));

  set("outdoors", "/open/main");

  setup();
}
