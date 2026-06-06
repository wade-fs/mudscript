// Room: /open/main/room/r23.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
	set( "build", 48 );
  set ("long", @LONG
你正走在一條山谷中, 也因此這兒車馬相接, 絡繹不絕, 最吸
引人的是, 這附近的山區常常有特種藥草出現, 因此採藥草的武林
人士不遠千里而來. 道路在此通往東方西方及南方.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/npc/bee" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"r22",
  "south" : __DIR__"r30",
  "north" : __DIR__"m10",
  "east" : __DIR__"r24",
]));

  setup();
}
