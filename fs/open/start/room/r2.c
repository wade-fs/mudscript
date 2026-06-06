// Room: /open/start/room/r2
inherit ROOM;

void create ()
{
  set ("short", "鄉間小路");
  set ("long", @LONG
這條小路的兩旁都長滿了跟人差不多高的稻草，讓你無
法看清楚四周的景物，看來這裡很少有人經過。

LONG);

  set("outdoors", "/open/start");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/start/room/r3",
  "north" : "/open/start/room/r1",
]));

  setup();
}
