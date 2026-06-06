// Room: /open/main/room/F5.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set( "build", 36 );
	set("long", @LONG
這裡一望無際的密林，四週伸手只見四指, 可見其黑的程度。南邊有一條小路
往山間行去,似乎通往蜀山.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "open/gsword/room/su-main",
  "north" : __DIR__"F2",
  "west" : __DIR__"F4",
  "east" : __DIR__"F6",
]));

	setup();
}
