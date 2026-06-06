// Room: /open/start/room/r3

inherit ROOM;

void create ()
{
  set ("short", "鄉間小路");
  set ("long", @LONG
這條小路的兩旁都長滿了跟人差不多高的稻草，讓你無
法看清楚四周的景物，看來這裡很少有人經過。
你注意到南邊有一間特別的建築物，令你想一探究竟。

LONG);

  set("exits", ([ /* sizeof() == 2 */
"south" : "/open/scholar/room/enter.c",
  "east" : __DIR__"r2",
]));
  set("outdoors", "/open/start");

  setup();
}
