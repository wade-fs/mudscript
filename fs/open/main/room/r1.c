// Room: /open/main/room/r1.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 48 );
  set ("long", @LONG
這是來往的商隊走出來的一條道路, 由於風大的關係, 路跡若隱若現
北邊是北盧關，如果不是因為開採油田帶來人潮, 這兒應該是人跡鮮至的
地方。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"d9",
//"north" : "/open/center/room/inn",
//mark by bss,why here can link to wa 4?
  "east" : __DIR__"d10",
  "southwest" : __DIR__"r2",
]));
  set("outdoors", "/open/main");

  setup();
}
