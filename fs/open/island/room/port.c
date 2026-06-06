inherit ROOM;

void create ()
{
  set ("short", "東津港區");
  set ("long", @LONG
這是一個正在開發的港口，許多的工人正在這裡
忙碌著，北邊原本是預定通往主港，但現在仍在施工
中，東邊則是通往偏港。

LONG);

  set("exits", ([ /* sizeof() == 2 */
   "west" : "/open/main/room/gy1",
  "east" : "/open/island/room/port2",
]));
  set("outdoors", "/open/main");

  setup();
}

