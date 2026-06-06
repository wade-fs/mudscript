// Room: /open/ping/room/edoor.c

inherit ROOM;

void create ()
{
  set ("short", "平南城東門");
  set ("long", @LONG
你眼前是一座兩丈高的城門,上面用楷書寫著 __平南城__ ,
這裡就是本朝南方重地平南城,本朝不但在此駐軍防衛,更以這裡
做為南進的基地,與苗人大大小小的戰鬥,已發生多場.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/guard-d1" : 1,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road1.c",
  "east" : "/open/main/room/r42",
]));

  setup();
}
