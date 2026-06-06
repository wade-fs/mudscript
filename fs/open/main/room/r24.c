// Room: /open/main/room/r24.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 24 );
  set ("long", @LONG
你正走在一條山谷中, 也因此這兒車馬相接, 絡繹不絕, 最吸
引人的是, 這附近的山區常常有特種藥草出現, 因此採藥草的武林
人士不遠千里而來. 道路在此呈東西走向.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m11",
  "west" : __DIR__"r23",
  "south" : __DIR__"m16",
  "east" : __DIR__"r25",
]));

  setup();
}
