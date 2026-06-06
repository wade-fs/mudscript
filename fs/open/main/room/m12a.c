// Room: /open/main/room/M12a.c

inherit ROOM;

void create()
{
	set("short", "環山長廊");
	set("long", @LONG
	這長廊不知道有多長多高，環繞著山而上，直
	入雲霧中。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"M13a",
  "westdown" : __DIR__"M11",
]));
	set("outdoors", "1");

	setup();
}
