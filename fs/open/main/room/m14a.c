// Room: /open/main/room/M14a.c

inherit ROOM;

void create()
{
	set("short", "環山長廊");
	set("long", @LONG
	再往上長廊就完全沒入雲霧中，朦朧間似乎看到不遠
	處有東西在燃燒。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"M13b",
  "westdown" : __DIR__"M13a",
]));
	set("outdoors", "1");

	setup();
}
