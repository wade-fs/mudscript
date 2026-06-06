// Room: /open/capital/room/ke1.c
inherit ROOM;

void create ()
{
  set ("short", "乾通天府");
  set ("long", @LONG
這理就是大名頂頂的乾通天所住的豪宅, 前門站的兩個守門的, 由此
可看出乾通天的勢力可以跟一些將士王侯差不多。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r18.c",
]));
  set("outdoors", "/open/capital");

  setup();
}
