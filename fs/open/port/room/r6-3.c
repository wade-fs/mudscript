// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","城牆邊");
  set ("long", @LONG
你正走在城牆邊的小巷上 . 北邊有道磚石砌成的階梯貼著城
牆而上 , 你可以順著階梯登上城牆 . 南邊是守衛隊頭辦公的地
方 , 東邊是守衛隊員們的休息室 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"east" : "/open/port/room/r6-4",
	"south" : "/open/port/room/r6-5",
	"west" : "/open/port/room/r6-2",
	"northup" : "/open/port/room/r6-6",
]));
	set("objects",([
	]));

  setup();
}
