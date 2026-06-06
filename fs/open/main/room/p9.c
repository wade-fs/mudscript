// Room: /open/main/room/p9.c

inherit ROOM;

void create ()
{
  set ("short", "沼澤");
	set( "build", 48 );
  set ("long", @LONG
這是一片充滿污泥的沼澤,幾支蘆葦抽枝而起,卻掩蓋不住
這裡的泥獰與惡臭,點點浮萍漂在地面的污水上,你恨不得敢快
離開.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/main/room/p3",
  "south" : "/open/main/room/p15",
  "west" : "/open/main/room/p8",
  "east" : "/open/main/room/p10",
]));

  set("outdoors", "/open/main");

  setup();
}
