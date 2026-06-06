// Room: /open/main/room/r22.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 12 );
  set ("long", @LONG
你正走在一條山谷中, 也因此這兒車馬相接, 絡繹不絕, 最吸
引人的是, 這附近的山區常常有特種藥草出現, 因此採藥草的武林
人士不遠千里而來. 道路在此呈東西走向.
LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/main/room/r21",
  "north" : "/open/main/room/m9",
  "south" : "/open/main/room/m15",
  "east" : "/open/main/room/r23",
]));

  setup();
}
