// Room: /open/main/room/r16.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
這是一條人煙稀少的小路,直直的往東西走去,誰也不知道他通
往哪.
LONG);

  set("exits", ([ /* sizeof() == 3 */
   "west" : "/open/capital/room/D02",
  "south" : "/open/main/room/s18",
  "east" : "/open/main/room/r17",
]));

  set("outdoors", "/open/main");


  setup();
}
