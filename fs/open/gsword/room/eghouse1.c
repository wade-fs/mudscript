// Room: /open/gsword/room/eghouse1.c
inherit ROOM;

void create ()
{
  set ("short", "小廣場");
  set ("long", @LONG
這是仙劍派劍士們用膳的地方，廣場中間數十張桌椅有條不紊的排列著，
北邊是大廚們開伙的工作房，直往南走，通往仙劍派眾師兄弟們的寢室。
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/gsword/room/eghouse2",
  "north" : "/open/gsword/room/kitchen",
  "east" : "/open/gsword/room/eghouse.c",
]));

  setup();
}
