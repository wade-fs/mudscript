// Room: /open/main/room/r43.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
	set( "build", 24 );
  set ("long", @LONG
你走在灰塵滾滾的石子路上，這裡已經相當接近苗疆了，你
的西方，即是本朝西南重鎮: 平南城. 本朝在此駐有重兵，以防
範苗疆來的侵略. 道路在此則往北往東和往西.
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/wu/npc/k_tiger" : 1,
  "/open/main/obj/torch" : 1,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L24",
  "north" : __DIR__"r39",
  "west" : __DIR__"r42",
  "east" : __DIR__"r44",
]));

  setup();
}
