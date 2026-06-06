// Room: /open/capital/room/r42.c

inherit ROOM;

void create ()
{
  set ("short", "日升馳道");
  set ("long", @LONG
城東的車馬大道。為了方便大批禁衛軍的通行特地開闢的石板大道
。路面相當寬敞，比一般胡同大上五倍有餘，想想十幾年前與關外異族
打仗時軍隊在這來往奔馳的氣勢，就覺得神往不已。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r43",
  "southwest" : __DIR__"r41",
]));

  set("gopath", "southwest");

  setup();
}
