// Room: /open/main/room/r13.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
	道路在這裡開始轉而向東，北方的森林並不濃密，
	看起來像是有人時常通行的樣子。

LONG);

  set("outdoors", "/open/main");
  set("build", 24);
  set("exits", ([ /* sizeof() == 4 */
  "westup" : "/open/poison_hole/room01",
  "east" : __DIR__"r14.c",
  "north" : __DIR__"f13",
  "south" : __DIR__"r20",
]));

  setup();
}
