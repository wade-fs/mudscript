// Room: /open/main/room/p14.c

inherit ROOM;

void create ()
{
  set ("short", "沼澤");
	set( "build", 12 );
  set ("long", @LONG
這是一片充滿污泥的沼澤,幾支蘆葦抽枝而起,卻掩蓋不住
這裡的泥獰與惡臭,點點浮萍漂在地面的污水上,你恨不得敢快
離開.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/main/room/p8",
  "west" : "/open/main/room/p13",
  "south" : "/open/main/room/f12",
  "east" : "/open/main/room/p15",
]));

  set("outdoors", "/open/main");

  setup();
}
