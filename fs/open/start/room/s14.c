// Room: /open/start/room/s14.c

inherit ROOM;

void create ()
{
  set ("short", "東村口");
  set ("long", @LONG
這裡是凌雲村東面的村口，從這兒一直往東可以通
往中央驛站，那裡是全國交通的要衝，許多人都會在那
聚集。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/start/room/s11",
  "east" : "/open/main/room/r21",
]));

  set("outdoors", "/open/start");

  setup();
}
