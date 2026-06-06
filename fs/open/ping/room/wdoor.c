// Room: /open/ping/room/wdoor.c

inherit ROOM;

void create ()
{
  set ("short", "平南城西門");
  set ("long", @LONG
你看到一座高二丈的城門,城牆上有巨石撞擊的痕跡,包鐵
的大城門也有薰黑碰撞的跡像, 苗人的入侵看來只是幾天前的
事,守城的將士門正忙著修補城牆,等待著下次苗人的來襲.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/guard-d1" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/main/room/r41",
  "east" : __DIR__"road6.c",
]));

  setup();
}
