// Room: /open/tendo/room/l1.2.c

inherit ROOM;

void create()
{
	set("short", "浮橋");
	set("long", @LONG
眼前的道觀如巨人般的豎立著，在雲霧中看不清它到底是浮在空
中還是建築在山頂，裡面住著的不知是那位隱世的高人。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"l1.1",
  "enter" : __DIR__"t03",
]));
  set("outdoors",1);
	setup();
}
