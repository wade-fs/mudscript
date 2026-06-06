// Room: /open/main/room/M12.c

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
  "westup" : __DIR__"M11",
  "eastdown" : __DIR__"M13",
]));
	set("outdoors", "1");

	setup();
}
