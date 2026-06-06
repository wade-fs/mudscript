// Room: /open/prayer/room/tangi/tangi1-35.c

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG

    柘一間廚房,天機門的廚師跑堂和休息的地方
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tangi1-36.c",
]));
	set("no_clean_up", 0);

	setup();
	}
