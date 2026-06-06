// Room: /open/main/room/[6].c

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", @LONG
這是一間什麼也沒有的空房間。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r41",
  "east" : __DIR__"r42",
]));

	setup();
}
