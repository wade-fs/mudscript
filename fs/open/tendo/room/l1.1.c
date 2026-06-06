// Room: /open/tendo/room/l1.1.c

inherit ROOM;

void create()
{
	set("short", "浮橋");
	set("long", @LONG
往下看是一片迷濛的雲霧，但這座橋竟然不需要橋墩的支撐只靠
兩端的銜接還如此的平穩，實在太不可思議了。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"l1.2",
  "south" : __DIR__"door",
]));
  set("outdoors",1);
	setup();
}
