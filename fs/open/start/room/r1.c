// Room: /open/start/room/r1

inherit ROOM;

void create ()
{
  set ("short", "鄉間小路");
  set ("long", @LONG
這條小路的兩旁都長滿了跟人差不多高的稻草，讓你無
法看清楚四周的景物，看來這裡很少有人經過。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/start/room/r2",
  "north" : "/open/start/room/f22",
]));

  set("outdoors", "/open/start");

  setup();
}
