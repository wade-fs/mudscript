// Room: /open/start/room/s9.c

inherit ROOM;

void create ()
{
  set ("short", "北村口");
	set( "build", 1126 );
  set ("long", @LONG
這裡是凌雲村的村口，從這兒可以離開凌雲村，
傳說在北方的蜀中城可以到達仙劍派，或許你會有這
機緣找到那像謎一般的派門。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/main/room/r18",
  "south" : "/open/start/room/s5",
]));

  set("outdoors", "/open/start");

  setup();
}
