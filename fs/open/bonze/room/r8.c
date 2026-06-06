// Room: /open/soulin/room/r8.c

inherit ROOM;

void create()
{
	set("short", "候客亭");
	set("long", @LONG
	由於寺內有諸多的限制，例如女流不得進入寺中
	等，故造此候客亭讓來訪尋人的施主們有個休息
	等候的地方。
	往北過了寺門就進入了少林寺。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r2",
  "north" : __DIR__"D01",
]));
	set("light_up", "1");

	setup();
}
