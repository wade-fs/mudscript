// Room: /open/start/room/s8.c

inherit ROOM;

void create ()
{
  set ("short", "南村口");
	set( "build", 1262 );
  set ("long", @LONG
這裡是凌雲村南面的村口，往南過去是村民耕種的
田地，你可以看到許多農夫正辛勤的耕作著，也有幾隻
水牛在犁田，農田中的稻草人上停憩著幾隻不知死活的
鳥。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/start/room/s5",
  "south" : "/open/start/room/f3",
]));

  set("outdoors", "/open/start");

  setup();
}
