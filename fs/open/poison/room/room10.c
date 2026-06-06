// Room: /open/poison/room/room9
inherit ROOM;

void create ()
{
  set ("short", "執法堂側廳");
  set ("long", @LONG
這裡是執法堂的側廳，在此有一位使者坐在精細華麗的
檀木椅上，眼光精斂直視正廳，他就是魔界頂頂有名，無人
不曉的索魄使者，在此協助執法大長老辦案。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room8",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/envoy4" : 1,
]));

  setup();
}
